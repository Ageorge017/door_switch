#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include "pico/mutex.h"

struct LoggerProps {
    std::string message;
    std::map<std::string, std::string> metadata;
};

enum class LogLevel {
    INFO,
    ERROR,
    WARN
};

class Logger {
    private:
        Logger() {}
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        std::string get_datetime();
        void log(const LoggerProps& props, LogLevel log_type);

         static Logger* instance;
        static mutex_t mutex;

        
    public:
        static Logger* getInstance();
        void info(const LoggerProps& props);
        void error(const LoggerProps& props);
        void warn(const LoggerProps& props);

};

#endif
