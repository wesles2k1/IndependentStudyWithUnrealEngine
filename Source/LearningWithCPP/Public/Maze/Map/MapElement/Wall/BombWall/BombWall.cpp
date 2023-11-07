#include "BombWall.h"

MapSite* BombWall::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Ran into bomb wall! You exploded!"));
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Walk it off."));

    return this;
}