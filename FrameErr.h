//
// Created by raduc on 14.05.2023.
//

#ifndef OOP_FRAMEERR_H
#define OOP_FRAMEERR_H


#include <exception>
#include <stdexcept>

#include <string>

class FrameErr : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class bad_input : public FrameErr {
public:
    explicit bad_input (const std::string & mesaj) :
            FrameErr("eroare input: " + mesaj) {}
};

class end_frame : public FrameErr {
public:
    explicit end_frame (const std::string & mesaj) :
            FrameErr("eroare end_frame: " + mesaj) {}
};

#endif //OOP_FRAMEERR_H
