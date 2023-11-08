#include "MapGenerator.h"

// ------ //
// Public //
// ------ //

void UMapGenerator::SetMapTypes(TArray<FMapOption> givenMapTypes) {
    MapTypes() = givenMapTypes;
    
    // Format the new mapTypes
    PrepFMapOptions(MapTypes());
}

TArray<FMapOption> UMapGenerator::GetMapTypes() {
    return MapTypes();
}

Map* UMapGenerator::BuildMazeTwoRooms() {
    Map* mapTemp{nullptr};

    mapTemp = MakeMap();
    Room* r1 = RandomFactory(MapTypes())->MakeRoom(1);
    Room* r2 = RandomFactory(MapTypes())->MakeRoom(2);
    Door* theDoor = RandomFactory(MapTypes())->MakeDoor(r1, r2);

    mapTemp->AddRoom(r1);
    mapTemp->AddRoom(r2);

    r1->SetSide(Direction::North, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::East, theDoor);
    r1->SetSide(Direction::South, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(MapTypes())->MakeWall());

    r2->SetSide(Direction::North, RandomFactory(MapTypes())->MakeWall());
    r2->SetSide(Direction::East, RandomFactory(MapTypes())->MakeWall());
    r2->SetSide(Direction::South, RandomFactory(MapTypes())->MakeWall());
    r2->SetSide(Direction::West, theDoor);

    return mapTemp;
}

Map* UMapGenerator::BuildMazeProcedural() {
    Map* mapTemp{nullptr};

    mapTemp = MakeMap();
    Room* rootRoom = RandomFactory(MapTypes())->MakeRoom(1);

    mapTemp->AddRoom(rootRoom);
    TArray<Door*> incompleteDoors;

    // How can I store these rooms in a graph?
    // This needs to be done so rooms can share preexisting elements (like if a room happens to be placed adjacent to another room with an incomplete door or a wall)
    // Maybe rooms need a position member? (two ints, an x and a y)
    for(int i{1}; i < 99; i++) {
        // Map should probably hold a nextID value to use
        // Select incomplete door
        Room* roomTemp{BuildRoom(i + 1, MapTypes())};
        // Connect roomTemp to existing room
        // Note doors with no connections
        // Somehow, note any other existing adjacent rooms and their connections
        // Remove additional incomplete doors if happened to be complete
        mapTemp->AddRoom(roomTemp);
        // Add doors to list of incomplete doors
    }

    return mapTemp;
}

Map* UMapGenerator::BuildMazeTree() {
    Map* mapTemp{nullptr};

    mapTemp = MakeMap();
    Room* r1 = RandomFactory(MapTypes())->MakeRoom(1);

    mapTemp->AddRoom(r1);

    r1->SetSide(Direction::North, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::East, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::South, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(MapTypes())->MakeWall());

    return mapTemp;
}

Map* UMapGenerator::BuildMazeKruskal() {
    Map* mapTemp{nullptr};

    mapTemp = MakeMap();
    Room* r1 = RandomFactory(MapTypes())->MakeRoom(1);

    mapTemp->AddRoom(r1);

    r1->SetSide(Direction::North, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::East, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::South, RandomFactory(MapTypes())->MakeWall());
    r1->SetSide(Direction::West, RandomFactory(MapTypes())->MakeWall());

    return mapTemp;
}

// ------- //
// Private //
// ------- //

TArray<FMapOption>& UMapGenerator::MapTypes() {
    static TArray<FMapOption> mapTypes{ { {MapType::Default, 1.0f} } };
    return mapTypes;
}

Map* UMapGenerator::MakeMap() {
    return new Map();
}

Room* UMapGenerator::BuildRoom(int id, /*Direction direction, */TArray<FMapOption> mapTypes) {
    return RandomFactory(mapTypes)->MakeRoom(id);
}

MapFactory* UMapGenerator::RandomFactory(TArray<FMapOption>& factories) {
    MapFactory* selectedFactory{nullptr};

    // Generate a random number with the range of (0.0, 1.0]
    float roll = (static_cast<float>(rand()) / RAND_MAX);

    // Use the number to select a factory
    auto iter{factories.begin()};
    while(selectedFactory == nullptr && iter != factories.end()) {
        roll -= iter.operator*().odds;
        if(roll <= 0.0) {
            selectedFactory = iter.operator*().factory.ToMapFactory();
            // Use to see what factory was the result
            //std::cout << iter.operator*().factory << std::endl;
        }
        iter.operator++();
    }

    return selectedFactory;
}

void UMapGenerator::PrepFMapOptions(TArray<FMapOption>& factories) {
    TArray<FMapOption> tempFactories;

    // Prime the random seed
    srand(static_cast<unsigned int>(time(0)));

    // Composite duplicate entries
    for(auto iter = factories.CreateIterator(); iter; iter++) {
        bool isDuplicate{false};
        size_t index{0};
        // Check for duplicate factories
        for(auto iterOther = tempFactories.CreateIterator(); iterOther; iterOther++) {
            if(iter->factory == iterOther->factory) {
                isDuplicate = true;
                index = iterOther.GetIndex();
            }
        }
        if(isDuplicate) {
            // Composite with existing factory option
            tempFactories[index].odds += iter->odds;
        } else {
            // Add as a new factory
            tempFactories.Add(*iter);
        }
    }

    // Remove any entries with impossible odds
    for(auto iter = tempFactories.CreateIterator(); iter; ++iter) {
        // Only keep entries with non-zero positive odds
        if(iter->odds <= 0.0) {
            iter.RemoveCurrent();
            iter--;
        }
    }
    
    // Normalize odds so their sum is 1.0
    float sum{0.0};
    for(auto iter = tempFactories.CreateIterator(); iter; ++iter) {
        sum += iter->odds;
    }

    double multiplier = 1 / sum;
    for(auto iter = tempFactories.CreateIterator(); iter; ++iter) {
        iter->odds *= static_cast<float>(multiplier);
    }

    // Clear factories and copy tempFactories over
    factories.Empty();
    factories = tempFactories;

    // Default if every element has been removed (because of 0.0 odds)
    if(factories.IsEmpty()) {
        factories.Add({});
    }

    // Output the final list of factories for testing and debugging
    for(auto iter = factories.CreateIterator(); iter; iter++) {
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, *(iter->factory.GetString()));
        //std::cout << static_cast<std::string>(iter->factory) << ", " << iter->odds << std::endl;
    }
}