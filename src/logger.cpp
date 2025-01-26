#include "logger.h"

#include <iostream>

namespace cuttlefish {

LogLevel Logger::threshold = LogLevel::DEBUG;
std::mutex Logger::mutex;

void Logger::log(const LogLevel &level, const std::string_view &message) {
  if (level < Logger::threshold) {
    return;
  }

  std::lock_guard<std::mutex> lock(Logger::mutex);

  switch (level) {
  case LogLevel::DEBUG:
    std::cout << "[DEBUG]\t" << message << std::endl;
    break;
  case LogLevel::INFO:
    std::cout << "[INFO]\t" << message << std::endl;
    break;
  case LogLevel::ERROR:
    std::cerr << "[ERROR]\t" << message << std::endl;
    break;
  default:
    std::cerr << "Unexpected LogLevel" << std::endl;
    break;
  }
}

void Logger::debug(const std::string_view &message) {
  Logger::log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string_view &message) {
  Logger::log(LogLevel::INFO, message);
}

void Logger::error(const std::string_view &message) {
  Logger::log(LogLevel::ERROR, message);
}

} // namespace cuttlefish