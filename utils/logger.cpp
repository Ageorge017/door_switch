#include "logger.h"
#include <stdio.h>
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <mutex>

Logger* Logger::instance = nullptr;
mutex_t Logger::mutex;

Logger* Logger::getInstance() {
    std::lock_guard<mutex_t> lock(mutex);
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

std::string Logger::get_datetime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm* local_time = std::localtime(&now_c);

    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Logger::log(const LoggerProps& props, LogLevel log_type){
    std::string current_time = get_datetime();
    std::string log_type_str;

    switch (log_type) {
        case LogLevel::INFO:
            log_type_str = "INFO";
            break;
        case LogLevel::ERROR:
            log_type_str = "ERROR";
            break;
        case LogLevel::WARN:
            log_type_str = "WARN";
            break;
    }

    std::cout << log_type_str << ": " << current_time << " : " << props.message << std::endl;
    for (const auto& prop : props.metadata) {
        std::cout << " " <<  prop.first << " : " << prop.second << std::endl;
    }

}

void Logger::info(const LoggerProps& props) {
   log(props, LogLevel::INFO);
}

void Logger::error(const LoggerProps& props) {
    log(props, LogLevel::ERROR);
}

void Logger::warn(const LoggerProps& props) {
    log(props, LogLevel::WARN);
}

