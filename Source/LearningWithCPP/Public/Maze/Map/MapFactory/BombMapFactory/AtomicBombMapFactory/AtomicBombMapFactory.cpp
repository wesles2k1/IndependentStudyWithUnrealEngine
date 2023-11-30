#include "AtomicBombMapFactory.h"

// Factory Methods

ARoom* AtomicBombMapFactory::MakeRoom(int id) const {
    return new AAtomicBombRoom(id);
}