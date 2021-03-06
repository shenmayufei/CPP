#include "DigitalClock.h"
#include "ClockTimer.h"
#include <iostream>

DigitalClock::DigitalClock (ClockTimer* s) {
  subject_ = s;
  subject_->Attach(this);
}

DigitalClock::~DigitalClock () {
  subject_->Detach(this);
}

void DigitalClock::Update (Subject* the_changed_subject) {
  if (the_changed_subject == subject_) {
    Draw();
  }
}

void DigitalClock::Draw () {
  int hour = subject_->GetHour();
  int minute = subject_->GetMinute();
  int second = subject_->GetSecond();
  std::cout << "Digital clock: -[" << hour << ":" << minute << ":" << second << "]-" << std::endl;
}
