#include "LockWall.h"

MapSite* LockWall::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("There's a key hanging on the wall!"));
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("You don't think it's yours, though, so you better not take it."));

    return this;
}