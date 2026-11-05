#pragma once
#include "NPC.h"

class Evil : public NPC
{
public:
    Evil();

    void Create() override;

    ~Evil();
};