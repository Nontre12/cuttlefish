#ifndef CUTTLEFISH_LOGGER_H_
#define CUTTLEFISH_LOGGER_H_

#include <mutex>
#include <string>

namespace cuttlefish {

enum LogLevel { DEBUG, INFO, ERROR };

class Logger {
private:
  static LogLevel threshold;
  static std::mutex mutex;

  Logger() = default;

  static void log(const LogLevel &level, const std::string &message);

public:
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  static void debug(const std::string &message);
  static void info(const std::string &message);
  static void error(const std::string &message);
};

} // namespace cuttlefish

#endif // CUTTLEFISH_LOGGER_H_