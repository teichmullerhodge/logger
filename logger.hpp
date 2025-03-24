#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "../declarations/declarations.hpp"
#include <ctime>
#include <iostream>
#include <nlohmann/json.hpp>
/// @brief Log messages with different colors on the terminal.
class Logger {

private:
  static str get_current_time() {

    std::time_t rawtime;
    std::tm *timeinfo;
    char buffer[80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer, 80, "[%d/%m/%Y %H:%M:%S]", timeinfo);
    return buffer;
  }

public:
  static void success(str message) {
    std::cout << "\033[1;32m" << get_current_time() << " [SUCCESS] - "
              << message << "\033[0m" << '\n';
  }

  static void error(str message) {
    std::cout << "\033[1;31m" << get_current_time() << " [ERROR] - " << message
              << "\033[0m" << '\n';
  }

  static void warning(str message) {
    std::cout << "\033[1;35m" << get_current_time() << " [WARNING] - "
              << message << "\033[0m" << '\n';
  }

  static void info(str message) {
    std::cout << "\033[1;34m" << get_current_time() << " [INFO] - " << message
              << "\033[0m" << '\n';
  }

  static void json(nlohmann::json data) {
    std::cout << "\033[1;36m" << get_current_time() << " [JSON] - "
              << data.dump(4) << "\033[0m" << '\n';
  }
};

#endif
