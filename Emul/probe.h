#ifndef PROBE_H
#define PROBE_H

class Probe
{
public:
    Probe();

    double getPulseDuration() const { return pulseDuration; }
    void setPulseDuration(double duration) { pulseDuration = duration; }

    double getAveragingTime() const { return averagingTime; }
    void setAveragingTime(double avgTime) { averagingTime = avgTime; }

    double getInputPulsePower() const { return inputPulsePower; }
    void setInputPulsePower(double power) { inputPulsePower = power; }

private:
    double pulseDuration;
    double averagingTime;
    double inputPulsePower;
};

#endif // PROBE_H
