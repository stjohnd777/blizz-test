#pragma once

#include <string>
#include <chrono>

typedef std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::duration<long>
> TP;

using namespace std::chrono;

namespace dsj {
    namespace utils {
/**
 * <h4>Simple Timing Utility.
 *
 * <p>
 * The class will take time splits with start a stop. The splits are named with (key)
 * and the intended usage is start(key) stop(key).
 * </p>
 *
 * <h4> Example
 *
 *      while(irRunning) {
 * 			TimeMetrics::Start("DPU");
 *			auto bboxes = dnn->run(img).bboxes;
 *			TimeMetrics::Stop("DPU");
 *		}
 *		auto double average = TimeMetrics::Average("DPU");
 *
 * <p>
 * The stop call create a "duration" and place the result in vector mapped to key in question.
 * This allows for many running splits on the armed code location, precise placements, and simultaneous split
 * gathering.
 * </p>
 *
 * <p>
 * The Utility is designed to call start(key) and stop(key) in this order. If one call start and start then the
 * "timepoint" for start is over written.
 * </p>
 *
 * Calling stop(key) when there is not start "timepoint" throw and exception.
 * Calling Average on a key that does not exit throw an exception
 */
        class TimeMetrics {
        public:
            /**
             * start timer with name key and return timepoint
             */
            static std::chrono::time_point<std::chrono::high_resolution_clock> Start(std::string key);

            static std::chrono::time_point<std::chrono::high_resolution_clock>
            Start(std::pair<std::string, uint32_t> key);

            /**
             * end timer with key and return timepoint and internally
             * store duration
             */
            static std::chrono::time_point<std::chrono::high_resolution_clock> Stop(std::string key);

            static std::chrono::time_point<std::chrono::high_resolution_clock>
            Stop(std::pair<std::string, uint32_t> key);

            /**
             * get average duration in seconds of the all splits
             * with key
             */
            static double Average(std::string key);
            //static double Average(std::string cat,std::pair<std::string,uint32_t> key);

            /**
             * get total duration in seconds on this split
             */
            static double TotalTime(std::string key);
            //static double Average(std::string cat,std::pair<std::string,uint32_t> key);


            /**
             * how many splits on the key
             */
            static int GetRuns(std::string key);

            /**
             * get the duration on a particular run
             */
            static double GetDuration(std::string key, int index);

        };
    }
}
