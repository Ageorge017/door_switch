#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

struct LoggerProps {
    std::string message;
    std::map<std::string, std::string> metadata;
};

enum class LogLevel {
    INFO,
    ERROR
};

class Logger {
    private:
        std::string get_datetime();
        void log(const LoggerProps& props, LogLevel log_type);
    public:
        void info(const LoggerProps& props);
        void error(const char* message);
};

#endif
