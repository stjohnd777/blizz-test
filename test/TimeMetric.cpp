#include "TimeMetric.hpp"

#include <vector>
#include <map>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace dsj {
    namespace utils {
        map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock> > starts;
        map<string, vector<double> > durations;

        map<pair<string, uint32_t>, std::chrono::time_point<std::chrono::high_resolution_clock> > startsCK;

        std::chrono::time_point<std::chrono::high_resolution_clock> TimeMetrics::Start(std::string key) {

            //auto
            std::chrono::time_point<std::chrono::high_resolution_clock> start = high_resolution_clock::now();
            if (starts.find(key) != starts.end()) {
                auto it = starts.find(key);
                it->second = start;
            } else {
                starts[key] = start;
            }
            return start;
        }

        std::chrono::time_point<std::chrono::high_resolution_clock>
        TimeMetrics::Start(pair<std::string, uint32_t> key) {
            // expected top be unique by uint32_t
            std::chrono::time_point<std::chrono::high_resolution_clock> start = high_resolution_clock::now();
            startsCK[key] = start;
            return start;
        }


        std::chrono::time_point<std::chrono::high_resolution_clock> TimeMetrics::Stop(string key) {

            std::chrono::time_point<std::chrono::high_resolution_clock> stop = high_resolution_clock::now();
            duration<double> duration;
            if (starts.find(key) == starts.end()) {
                throw std::runtime_error("Stop Called With Start " + key);
            }
            auto start = starts[key];
            if (durations.find(key) == durations.end()) {
                vector<double> durationsForKey;
                durations[key] = durationsForKey;
            }
            duration = stop - start;
            durations[key].push_back(duration.count());
            starts.erase(starts.find(key));

            return stop;
        }

        std::chrono::time_point<std::chrono::high_resolution_clock> TimeMetrics::Stop(pair<std::string, uint32_t> key) {

            std::chrono::time_point<std::chrono::high_resolution_clock> stop = high_resolution_clock::now();

            if (startsCK.find(key) == startsCK.end()) {
                throw std::runtime_error("Stop Called Without Start ");
            }
            auto start = startsCK[key];
            string cat = key.first;
            if (durations.find(cat) == durations.end()) {
                vector<double> durationsForKey;
                durations[cat] = durationsForKey;
            }
            duration<double> duration = stop - start;
            durations[cat].push_back(duration.count());

            startsCK.erase(startsCK.find(key));

            return stop;
        }


        double TimeMetrics::Average(string key) {

            double sum = 0;
            double average = 0;


            if (durations.find(key) != durations.end()) {
                auto list = durations[key];
                for_each(begin(list), end(list),
                         [&](double duration) {
                             sum += duration;
                         });
                average = sum / (double) durations[key].size();
            } else {
                throw std::runtime_error("Average Called With No duration list " + key);
            }
            return average;
        }


        double TimeMetrics::TotalTime(string key) {

            double sum = 0;

            if (durations.find(key) != durations.end()) {
                auto list = durations[key];
                for_each(begin(list), end(list),
                         [&](double duration) {
                             sum += duration;
                         });
            } else {
                throw std::runtime_error("Average Called With No duration list " + key);
            }
            return sum;
        }


        int TimeMetrics::GetRuns(string key) {
            int runs = 0;
            if (durations.find(key) != durations.end()) {
                runs = durations[key].size();
            }
            return runs;
        }

        double TimeMetrics::GetDuration(string key, int index) {
            double d = 0;
            if (durations.find(key) != durations.end()) {
                auto duration = durations[key];
                d = duration[index];
            }
            return d;
        }

    }
}
