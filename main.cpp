#include <iostream>

using namespace std;

#include <random>
namespace
{
    const double Deviation = 1e-4;
    const double LightSpeed = 299792.;
    const int TraceResolution = 30;
    default_random_engine generator;
}

#include <vector>
class FiberHeterogenity;
class Fiber
{
public:
    Fiber()
        : length(0),
          attenuation(0),
          reflection(0)
    {
    }

    ~Fiber()
    {
        for(int i = 0; i < heterogenities.size(); ++i)
            delete heterogenities[i];
    }

    //! Длина ОВ в километрах
    double getLength() const { return length; }
    void setLength(double length) { this->length = length; }

    //! Список неоднородностей на ОВ
    vector<FiberHeterogenity*> & getHeterogenities() { return heterogenities; }
    void addHeterogenity(FiberHeterogenity *het) { heterogenities.push_back(het); }

    //! Коэффициент затухания ОВ в дБ/км
    double getAttenuation() const { return attenuation; }
    void setAtteniation(double attn) { attenuation = attn; }

    //! Групповой показатель преломления сердцевины ОВ
    double getReflection() const { return reflection; }
    void setReflection(double refl) { reflection = refl; }

private:
    double length;
    double attenuation;
    double reflection;
    vector<FiberHeterogenity*> heterogenities;
};

class Probe
{
public:
    Probe()
        : pulseDuration(0),
          averagingTime(0),
          inputPulsePower(0)
    {
    }

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

struct Faker
{
    static Fiber fiber()
    {
        Fiber f;
        f.setLength(85);
        f.setAtteniation(0.24);
        f.setReflection(1.468);
        return f;
    }

    static Probe probe()
    {
        Probe p;
        p.setAveragingTime(1);
        p.setInputPulsePower(-30);
        p.setPulseDuration(5 * 1e-9);
        return p;
    }
};


#include <random>
class Utils
{
public:
    static double fluctuation(double mean, double dev)
    {
        normal_distribution<double> distributor(mean, dev);
        return distributor(generator);
    }
};

#include <vector>
#include <cmath>
#include <iomanip>
#include "point.h"

class ReflectometerEmulator
{
public:
    ReflectometerEmulator(const Fiber &_context, const Probe &_probe)
        : fiber(_context),
          probe(_probe),
          traceResolution(TraceResolution)
    {
    }

    const vector<DPoint> &getTrace() const { return trace; }

    int getTraceResolution() const { return traceResolution; }
    void setTraceResolution(int resolution) { traceResolution = resolution; }

    void run()
    {
        const int noiseSize = (5 * 1000) / getTraceResolution();
        const int traceSize = fiber.getLength() * 1000 / getTraceResolution();
        trace.resize(traceSize+noiseSize);
        for(int i = 0; i < traceSize; ++i)
        {
            DPoint p;
            p.x = (double)((i + 1) * getTraceResolution()) / 1000.;
           // p.y = probe.getInputPulsePower() - Utils::fluctuation(fiber.getAttenuation(), Deviation) * p.x;
            trace[i] = p;
        }

        for(int i = traceSize; i < traceSize+noiseSize; ++i)
        {
            DPoint p;
            p.x = (double)((i + 1) * getTraceResolution()) / 1000.;
            p.y = Utils::fluctuation(trace[traceSize-1].y - 6, 0.6);
            trace[i] = p;
        }

    }

private:
    Fiber fiber;
    Probe probe;
    vector<DPoint> trace;

    //! Минимальное расстояние между двумя точками рефлектограммы в метрах
    int traceResolution;
};

#include <string>
#include <cstdio>
#include <iomanip>
class OutputProcessor
{
public:
    OutputProcessor(const string& filename)
    {
        freopen(filename.data(), "w", stdout);
    }

    void close() { fclose(stdout); }

    void writeTrace(const vector<DPoint> &trace)
    {
        cout << fixed << setprecision(12);

        cout << trace.size() << endl;
        for(int i = 0; i < trace.size(); ++i)
            cout << trace[i].x << " " << trace[i].y << endl;
    }
};

class InputProcessor
{
public:
    InputProcessor(const string& filename)
    {
        freopen(filename.data(), "r", stdin);
    }

    void close() { fclose(stdin); }

    void readFiber(Fiber &fiber)
    {
        double lenght = 0.;
        cin >> lenght;
        fiber.setLength(lenght);

        int keyPointsCount = 0;
        cin >> keyPointsCount;
        for(int i = 0; i < keyPointsCount; ++i)
        {
            // TODO: read key points, create from factory, add to fiber;
        }
    }

    void readProbe(Probe &probe)
    {
        double duration = 0.;
        cin >> duration;
        probe.setPulseDuration(duration);

        double avgTime = 0.;
        cin >> avgTime;
        probe.setAveragingTime(avgTime);
    }

};

int main()
{
    Fiber fiber = Faker::fiber();
    Probe probe = Faker::probe();

    /*
    const string inputFile = "";
    InputProcessor ip(inputFile);
    ip.readFiber(fiber);
    ip.readProbe(probe);
    */

    ReflectometerEmulator emul(fiber, probe);
    emul.run();

    const string outputFile = "/home/ratuvog/input.txt";
    OutputProcessor op(outputFile);
    op.writeTrace(emul.getTrace());
    op.close();

    return 0;
}

