#include "Time.h"
#include <iostream>
#include <ctime>

Time_::Time_() {
    std::time_t now = std::time(nullptr);
    std::tm* timeinfo = std::localtime(&now);

    hour = timeinfo->tm_hour;
    minutes = timeinfo->tm_min;
    seconds = timeinfo->tm_sec;
    format = true;

    normalize();
}

Time_::Time_(int hour, int minutes, int seconds, bool format) {
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;

    normalize();
}

Time_::Time_(const Time_& obj) {
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    this->format = obj.format;
}

Time_& Time_::operator=(const Time_& obj) {
    if (this != &obj) {
        this->hour = obj.hour;
        this->minutes = obj.minutes;
        this->seconds = obj.seconds;
        this->format = obj.format;

        normalize();
    }
    return *this;
}

Time_::~Time_() {
}

void Time_::setHour(int hour) {
    this->hour = hour;

    normalize();
}

int Time_::getHour()const {
    return hour;
}

void Time_::setMinutes(int minutes) {
    this->minutes = minutes;

    normalize();
}

int Time_::getMinutes()const {
    return minutes;
}

void Time_::setSeconds(int seconds) {
    this->seconds = seconds;
    normalize();
}

int Time_::getSeconds()const {
    return seconds;
}

void Time_::setFormat(bool format) {
    this->format = format;
}

bool Time_::getFormat()const {
    return format;
}

bool Time_::valid()const {
    return (hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
}

void Time_::tickTime() {
    seconds++;
    if (seconds >= 60) {
        seconds -= 60;
        minutes++;
        if (minutes >= 60) {
            minutes -= 60;
            hour++;
            if (hour >= 24) {
                hour -= 24;
            }
        }
    }

    normalize();
}

void Time_::untickTime() {
    if (seconds == 0) {
        seconds = 59;
        minutes--;
        if (minutes == -1) {
            minutes = 59;
            hour--;
            if (hour == -1) {
                hour = 23;
            }
        }
    }
    else {
        seconds--;
    }

    normalize();
}

void Time_::showTime()const {
    if (format) {
        std::cout << (hour < 10 ? "0" : "") << hour << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << " UTC" << std::endl;
    }
    else {
        std::cout << (hour % 12 == 0 ? 12 : hour % 12) << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << (hour < 12 ? " AM" : " PM") << std::endl;
    }
}

bool Time_::operator==(const Time_& obj)const& {
    return (hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds);
}

bool Time_::operator!=(const Time_& obj)const& {
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj)const& {
    if (hour > obj.hour) {
        return true;
    }
    else if (hour == obj.hour && minutes > obj.minutes) {
        return true;
    }
    else if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds) {
        return true;
    }
    else {
        return false;
    }
}

bool Time_::operator<(const Time_& obj)const& {
    return !(*this > obj || *this == obj);
}

bool Time_::operator>=(const Time_& obj)const& {
    return (*this > obj || *this == obj);
}

bool Time_::operator<=(const Time_& obj)const& {
    return !(*this > obj);
}

Time_& Time_::operator+=(int s) {
    seconds += s;
    if (seconds >= 60) {
        int m = seconds / 60;
        seconds %= 60;
        minutes += m;
        if (minutes >= 60) {
            int h = minutes / 60;
            minutes %= 60;
            hour += h;
            if (hour >= 24) {
                hour -= 24;
            }
        }
    }

    normalize();
    return *this;
}

Time_& Time_::operator-=(int s) {
    this->seconds -= s;
    if (seconds < 0) {
        int m = -seconds / 60;
        seconds += 60 * m;
        minutes -= m;
        if (minutes < 0) {
            int h = -minutes / 60;
            minutes += 60 * h;
            hour -= h;
            if (hour < 0) {
                hour += 24;
            }
        }
    }

    normalize();
    return *this;
}

Time_& Time_::operator+=(float m) {
    this->minutes += m;
    if (minutes >= 60) {
        int h = minutes / 60;
        minutes %= 60;
        hour += h;
        if (hour >= 24) {
            hour -= 24;
        }
    }

    normalize();
    return *this;
}

Time_& Time_::operator-=(float m) {
    this->minutes -= m ;
    if (minutes < 0) {
        int h = -minutes / 60;
        minutes -= 60;
        hour -= h;
        if (hour < 0) {
            hour += 24;
        }
    }

    normalize();
    return *this;
}

Time_& Time_::operator+=(long h) {
    this->hour += h;
    if (hour >= 24) {
        hour -= 24;
    }

    normalize();
    return *this;
}

Time_& Time_::operator-=(long h) {
    this->hour -= h;
    if (hour < 0) {
        hour += 24;
    }

    normalize();
    return *this;
}

Time_ Time_::operator+(int s)const& {
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(int s)const& {
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(float m)const& {
    Time_ tmp = *this;
    tmp += minutes;
    return tmp;
}

Time_ Time_::operator-(float m)const& {
    Time_ tmp = *this;
    tmp -= minutes;
    return tmp;
}

void Time_::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    else if (seconds < 0) {
        minutes += (seconds - 59) / 60;
        seconds = 60 + seconds % 60;
    }

    if (minutes >= 60) {
        hour += minutes / 60;
        minutes %= 60;
    }
    else if (minutes < 0) {
        hour += minutes / 60;
        minutes = 60 + minutes % 60;
    }

    if (hour >= 24) {
        hour %= 24;
    }
    else if (hour < 0) {
        hour = 24 + hour % 24;
    }
        
 }
