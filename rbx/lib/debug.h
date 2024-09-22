//
// Created by alpluspluss on 22/9/2024 AD.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <sstream>
#include <string>
#include <tuple>
#include "types/coroutine_t.h"

namespace rbx::lib::debug
{
    std::string traceback(const std::string& message, int level = 1);
    std::string traceback(const types::thread_t& thread, const std::string& message, int level = 1);
    std::tuple<std::string> info(int level, const std::string& options = "");
    std::tuple<std::string> info(const std::function<void()>& func, const std::string& options = "");
    std::tuple<std::string> info(const types::thread_t& thread, int level, const std::string& options = "");

    void profilebegin(const std::string& label);
    void profileend();

    std::string getmemorycategory();
    std::string setmemorycategory(const std::string& tag);
    void resetmemorycategory();
    void dumpcodesize();

}

#endif // DEBUG_H
