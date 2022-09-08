#pragma once

#include<Vanilla3.h>
#include<Parameters.h>
#include<MCStatistics.h>
#include<chrono>
#include<vector>
#include<memory>

class TerminatorInner {
public:
    TerminatorInner() :Terminate(0) {}
    virtual bool IfContinue() = 0;
    virtual TerminatorInner* clone()const = 0;
protected:
    bool Terminate;
};
class TerminatorTimeSpent : public TerminatorInner {
public:
    TerminatorTimeSpent(std::chrono::duration<int> Seconds_) :started(0), TerminatorInner(), Seconds(Seconds_) {
    }
    virtual bool IfContinue() override {
        if (!started) {
            started = 1;
            Stop = std::chrono::system_clock::now() + Seconds;
        }
        Terminate = std::chrono::system_clock::now() >= Stop;
        return Terminate;
    }
    TerminatorTimeSpent* clone()const override {
        return new TerminatorTimeSpent(*this);
    }
private:
    bool started;
    std::chrono::duration<int> Seconds;
    std::chrono::system_clock::time_point Stop;
};

class TerminatorPathsDone : public TerminatorInner {

    TerminatorPathsDone(unsigned long MaxPaths_) :MaxPaths(MaxPaths_), TerminatorInner(), PathsDone(0) {
    }
    virtual bool IfContinue() override {
        PathsDone++;
        Terminate = PathsDone >= MaxPaths;
        return Terminate;
    }
    virtual TerminatorPathsDone* clone()const override {
        return new TerminatorPathsDone(*this);
    }
private:
    unsigned long PathsDone;
    unsigned long MaxPaths;
};

class TerminatorAny :public TerminatorInner {
    TerminatorAny(std::vector<std::unique_ptr<TerminatorInner>> Termiantors_) :TerminatorInner() {
        for (auto&& s : Termiantors_)
            Terminators.push_back(std::make_unique<TerminatorInner>(s->clone()));
    }
    bool IfContinue()override {
        for (auto&& s : Terminators)
        {
            if (!(s->IfContinue())) {
                Terminate = 1;
                return 0;
            }
        }
        return 1;
    }
    TerminatorAny* clone()const override {
        return new TerminatorAny(Terminators);
    }
private:
    std::vector<std::unique_ptr<TerminatorInner>> Terminators;
};

void SimpleMonteCarlo5(const VanillaOption& TheOption,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    StatisticsMC& gatherer, TerminatorInner& Terminator);
