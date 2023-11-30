#pragma once

#include "../BombMapFactory.h"

#include "../../../MapElement/Room/BombRoom/AtomicBombRoom/AAtomicBombRoom.h"

class AtomicBombMapFactory: public BombMapFactory {
    public:
        // Factory Methods
        virtual ARoom* MakeRoom(int id) const;

    // Allow for Singleton behavior
    protected:
        AtomicBombMapFactory() {};
    friend class Singleton;
};