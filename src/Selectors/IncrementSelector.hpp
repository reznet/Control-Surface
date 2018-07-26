#pragma once

#include "Selector.hpp"
#include <Hardware/IncrementButton.hpp>

class IncrementSelector : public virtual Selector {
  public:
    IncrementSelector(Selectable &selectable, setting_t numberOfSettings,
                      const IncrementButton &button, bool wrap = true)
        : Selector(selectable, numberOfSettings), button(button), wrap(wrap) {}

    void beginInput() override { button.begin(); }

    void update() override {
        if (button.getState() == IncrementButton::Increment)
            increment();
    }

    void increment() {
        setting_t setting = get();
        setting++;
        if (setting == getNumberOfSettings())
            setting = wrap ? 0 : setting - 1;
        set(setting);
    }

  private:
    IncrementButton button;
    bool wrap;
};