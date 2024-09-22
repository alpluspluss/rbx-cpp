//
// Created by alpluspluss on 22/9/2024 AD.
//

#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>
#include <string>
#include <vector>
#include "../types/buffer_t.h"

namespace rbx::lib::buffer
{
    types::buffer_t create(size_t size);

    types::buffer_t fromstring(const std::string& str);
    std::string tostring(const types::buffer_t& b);
    size_t len(const types::buffer_t& b);

    int8_t readi8(const types::buffer_t& b, size_t offset);
    uint8_t readu8(const types::buffer_t& b, size_t offset);
    int16_t readi16(const types::buffer_t& b, size_t offset);
    uint16_t readu16(const types::buffer_t& b, size_t offset);
    int32_t readi32(const types::buffer_t& b, size_t offset);
    uint32_t readu32(const types::buffer_t& b, size_t offset);
    float readf32(const types::buffer_t& b, size_t offset);
    double readf64(const types::buffer_t& b, size_t offset);
    std::string readstring(const types::buffer_t& b, size_t offset, size_t count);

    void writei8(types::buffer_t& b, size_t offset, int8_t value);
    void writeu8(types::buffer_t& b, size_t offset, uint8_t value);
    void writei16(types::buffer_t& b, size_t offset, int16_t value);
    void writeu16(types::buffer_t& b, size_t offset, uint16_t value);
    void writei32(types::buffer_t& b, size_t offset, int32_t value);
    void writeu32(types::buffer_t& b, size_t offset, uint32_t value);
    void writef32(types::buffer_t& b, size_t offset, float value);
    void writef64(types::buffer_t& b, size_t offset, double value);
    void writestring(types::buffer_t& b, size_t offset, const std::string& value, size_t count);

    void copy(types::buffer_t& target, size_t targetOffset, const types::buffer_t& source, size_t sourceOffset, size_t count);
    void fill(types::buffer_t& b, size_t offset, uint8_t value, size_t count);

}

#endif
