//
// Created by alpluspluss on 22/9/2024 AD.
//

#ifndef COROUTINE_H
#define COROUTINE_H

#include <functional>
#include <string>
#include <tuple>
#include "types/coroutine_t.h"

namespace rbx::lib::coroutine
{
    template<typename... args>
    types::coroutine_t create(std::function<void(args...)> f);

    template<typename... args, typename... returnTypes>
    std::tuple<bool, std::tuple<returnTypes...>> resume(types::coroutine_t& co, args... arguments);

    template<typename... yieldTypes>
    std::tuple<yieldTypes...> yield(yieldTypes... results);
    std::string status(const types::coroutine_t& co);

    template<typename... returnTypes>
    std::variant<bool, std::tuple<returnTypes...>> close(types::coroutine_t& co);

    template<typename... args, typename... returnTypes>
    std::function<std::tuple<returnTypes...>(args...)> wrap(std::function<void(args...)> f);

    types::coroutine_t running();
    bool isyieldable();

}

#endif
