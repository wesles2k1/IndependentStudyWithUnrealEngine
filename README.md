# Independent Study With Unreal Engine - Progress
This is a repository to hold an Unreal Engine project with the purpose of developing C++ skills within Unreal Engine, as well as to use them to learn more about design patterns. This project is for-credit in the form of an Independent Study at PennWest Edinboro University.

This project will be divided into three portions: first, to get acquainted with the usage of C++ within Unreal Engine, then to learn more about design patterns that may be useful in game design with C++, and lastly, to combine the first two portions together to implement design patterns into an Unreal Engine project with C++.

## Table of Contents
- [Part 1 - C++ in Unreal Engine](#part1)
  - [Week 1 - Setup, C++ Basics, and Temperature Converter](#week1)
    - [8/29/2023 - Created GitHub repository and added Unreal Project](#8/29/2023)
    - [9/1/2023 - Level and Interaction System](#9/1/2023)
    - [9/2/2023 - Built Temperature Converter UI](#9/2/2023)
    - [9/3/2023 - Built and Implemented Temperature Converter C++ Object](#9/3/2023)
  - [Week 2 - Documentation, Enumerations, and an Animal Selector](#week2)
    - [9/5/2023 - New Parameters and Documentation](#9/5/2023)
    - [9/7/2023 - Built Animal Selector UI](#9/7/2023)
    - [9/8/2023 - Built CAnimalT Enum and Completed Animal Selector](#9/8/2023)
  - [Week 3 - C++ Actors as Input and Output, Spawning Animals, and the First Factory](#week3)
    - [9/12/2023 - Building an Animal Hierarchy and Starting the Factory](#9/12/2023)
    - [9/15/2023 - Functioning Factory and Mesh Problems](#9/15/2023)

<a name="part1"></a>
## Part 1 - C++ in Unreal Engine

<a name="week1"></a>
### Week 1 - Setup, C++ Basics, and Temperature Converter

  For the first week of this project, a main goal was set to have a simple temperature converter working that involves calculations within a C++ object that communicates back and forth with a higher-level Blueprint. This goal serves as a way to introduce the Blueprint/C++ communication process and methods.

<a name="8/29/2023"></a>
#### 8/29/2023 - Created GitHub repository and added Unreal Project!

  To begin the project, an Unreal Engine project was created and used to create this GitHub repository. This was done primarily by following a tutorial by [Matt Aspland](https://www.youtube.com/watch?v=n3x1fErlmYA&t=6s) tutorial. Unreal Engine 5.2 is being used, and this part of the project is built upon the default Third Person template.
  
  ![GitHubSetup](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/f8ca9508-3b5b-4c89-ad7d-20c1f579c98e)

  Once the repository was set up, a basic version of this README was filled out, a test push was made with a minimal change in the project, and a few other small things were done to ensure the project is ready to be added to.
  
  ![GitHubInitialPushes](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/3126d37c-38ed-4dda-ba44-dc4f66110df9)

<a name="9/1/2023"></a>
#### 9/1/2023 - Level and Interaction System

  As a first move, the default ThirdPersonMap was duplicated and adjusted to better fit the needs of this project. As the first goal is to create a temperature converter, it seemed appropriate to make a simple interaction system that may be reused for future weeks' goals. A BPInteractableBase Blueprint was made to support later uses, and a BPTemperatureConverter was derived for the focus of this week. It's job is simply to be a tangible object in the world that can be interacted with to provide the user with a prompt to input data.
  
  Additionally, two tutorials were followed along to get acquainted with basic use of C++ in Unreal Engine in preparation for the temperature converter (tutorials by [Gorka Games](https://www.youtube.com/watch?v=HNfpKFER2hI) and [Ryan Laley](https://www.youtube.com/watch?v=FBpnOuCgHu4)). Comments within the Blueprints created for each tutorial go into further detail, but their uses are no longer required for the project other than to reference later.

<a name="9/2/2023"></a>
#### 9/2/2023 - Built Temperature Converter UI

  The last step before stepping into C++ was to create an interface through which the user may input data, a temperature they wish to have converted. This UI, named TemperatureWidget, was build with the future C++ object implementation in mind and was made a separate object from the BPTemperatureConverter. It consists of a back button to exit, a button to calculate the conversion, and two text boxes for the user to type in: one for a temperature numerical value and the other for a unit, either Fahrenheit or Celcius, the value is given as.
  
  ![TemperatureWidget](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/b93115c3-a9f9-4ff6-9d6d-926fbecaab05)


<a name="9/3/2023"></a>
#### 9/3/2023 - Built and Implemented Temperature Converter C++ Object

  This day saw the creation and success of a temperature conversion using a C++ class called `UCTemperatureCalculator`. This class consists of a singular Calculate function, whose purpose is to take in a temperature numerical value and a unit to calculate the other unit's value. The following is the TemperatureWidget Blueprint:
  
  ![BPTemperatureWidget](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/7497e97e-bd05-4c29-8551-f13d96e5f89c)
  
  The bulk of the nodes make up the Blueprint-end behavior, such as opening and closing the UI, (although it is also where the `UCTemperatureCalculator` is instantiated,) while the smaller portion on the bottom is where the `UCTemperatureCalculator`'s `Calculate` function is called:
  
  ![CTemperatureCalculator_CalculateBP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/96feb8c2-66a8-4e10-8a71-ffaf5b7ced9d)

  The `text` from the input textboxes could be converted to strings, but it felt appropriate to attempt working with this new datatype, known as `FText`, and use it as the parameters and return value to keep as much work in the C++ portion as possible. All it really meant, though, was just converting them to `FStrings` (Unreal Engine's equivalent to the usual `std::string`) and working with them from there.
  
  In addition to the actual conversion, messages were generated to be returned in the case of unexpected or wrong input for clarity. The following are pictures of the function within the implementation and header files, respectively:
  
  ![CTemperatureCalculatorCPP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/2904105a-a79c-4e13-8ad2-d8662aa563ca)
  
  ![CTemperatureCalculatorH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/ad79bbea-a82e-4bfd-ac8e-c7bb915d5441)

  Here, a demonstration of it functioning can be seen:

  https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/8bda65e3-a630-44fe-ab83-88591a86d855

  Note: Small changes were made between the recording of this video and the screenshots of `CTemperatureCalculator`, hence the appearance of "C" and "F" in the output messages.

<a name="week2"></a>
### Week 2 - Documentation, Enumerations, and an Animal Selector

  For the second week, the main goal is to make an interface that lists a selection of animals that the user may select from to receive an output through the use of a slightly more complicated C++ class and an enumerator as both a parameter and return type. Additional goals for this week include experimenting with additional data types (`int`, `float`, and `FString`) as parameters and return types, reworking this README file for more clear documentation, and looking into a better C++ file structure.

<a name="9/5/2023"></a>
#### 9/5/2023 - New Parameters and Documentation

  To begin the week, the secondary goal of extra data types as parameters and return values was explored. To do so, the temperature calculator was revisited and the `Calculate` function was duplicated for adjustment. This new function took in parameters of a `float` and an `FString` while the return value was made into a `float` instead of `FText`s (the `FText` casts were just done in the Blueprint). While this proved to work fine and showed that these data types may be used normally, the function was named `CalculateBad` since it couldn't account for unexpected/wrong input as well as before. The following are its implementation and declaration:
  
  ![CTemperatureCalculator_CalculateBadCPP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/bef8cc2b-2eaa-4417-bc9d-3461fff1fdcd)
  
  ![CTemperatureCalculator_CalculateBadH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/e054e19d-1f2c-4a8f-a389-4969f6b78f61)

  The Blueprint interaction:
  
  ![CTemperatureCalculator_CalculateBadBP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/dbdfdb1c-59f5-4b23-a176-d562f5db6716)

  The results:
  
  ![CalculateBadResultsFloat](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/4c342781-9d62-4d3f-83bc-26ff3c7c7f42)

  After this experiment, one more step was taken to consider `int`. The `CalculateBad` function was altered again to return an `int` that was simply a cast from the previous `float` value (further emphasizing the "Bad" of the function's name):
  
  ![CTemperatureCalculator_CalculateBadIntReturn](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/56df9cea-51ed-4686-85ec-930b048ae53a)

  The altered Blueprint:
  
  ![CTemperatureCalculator_CalculateBadBPInt](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/28204b4a-9ea8-4b2d-b691-9cbd8305a43f)

  The (Bad) results:
  
  ![CalculateBadResultsInt](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/225e3d4b-627f-4b95-90e9-bce340c46ad0)

<a name="9/7/2023"></a>
#### 9/7/2023 - Built Animal Selector UI

  The UI for the next goal, the animal selector, has been created. Animals will be dynamically listed according to a predetermined array of AnimalT enumerations. Each animal will have an exclusive radio button, and the select button will grab that animal's associated enumeration, pass it down to a C++ object, and retreive a string to output.

  ![AnimalSelectorBasicMenu](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/f810bda4-f590-4db8-8d4e-63575444f371)

<a name="9/8/2023"></a>
#### 9/8/2023 - Built CAnimalT Enum and Completed Animal Selector

  The day began simply with the construction of an enumeration, CAnimalT, to be used in this week's project. CAnimalT began as an unscoped enumeration, but upon seeing in many tutorials that scoped enumerations were being used, the topic was researched more and determined to be the way to go here.
  
  ![CAnimalTH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/f9bdf0f1-b46c-49dc-bbe1-4d9600a1cd74)

  With the creation of the CAnimalT, it was time to give it some functionality. The goals of this week is to have an enumeration that can be:

  - Incremented
  - Converted to a string, and
  - Converted to an action

  For the purposes of this week, converting an CAnimalT to an "action" meant returning a string of what noise an animal makes (where the conversion to a "string" refers to returning the enumeration itself in string form). The functionality for this can be seen below:
  
  ![CAnimalSelectorH](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/9fe015e5-40da-4ff6-9606-f0daea81f775)
  
  ![CAnimalSelectorIncrement](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/44e672a5-29b6-485a-a45a-78e5d184425f)
  
  ![CAnimalSelectorDecrement](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/425007ab-ada3-4555-9f8c-5188dcdbe2a6)
  
  ![CAnimalSelectorToString Action](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/27f3c0da-8003-4a70-abb4-ae699f265c76)

  These were then worked into the widget Blueprints for use. The widget made yesterday didn't seem to have any good way to demonstrate the incrementation of CAnimalT, so a second was created to be formatted differently. However, the first version was so close to being done and seems different enough to warrent keeping it, so there are two slightly different, but different enough versions of the Animal Selector. Below is a part of the second version, where both the incrementation functionality and the action fucntionality were implemented:
  
  ![AnimalSelectorMenuWidget2BP](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/13043de6-a521-4069-a472-f40d0def390a)

  Finally, here are the results of this days work. The first video demonstrates the first, original Animal Selector, while the second demonstrates the new version.
  
  https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/1d5eaee1-d444-4f3d-8bbb-361e9b175d70
  
  https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/7768b5c6-d622-4f9c-b683-8903f4822b74

<a name="week3"></a>
### Week 3 - C++ Actors as Input and Output, Spawning Animals, and the First Factory

  For what is likely the last week in the first part of this project, the overarching goal is to create a simple class hierarchy in C++, use it to demonstrate custom object communication via parameters and/or return values, and to build a simple factory in C++ to create objects from this hierarchy. This will be done by expanding the Animal Selector that was built last week: A hierarchy of CAnimals will be build from which to derive CDog, CCat, and so on. Hopefully, by the end of the week the Animal Selector may be used to spawn tangible animals. If time permits, automatic movement may be added to these animals.

<a name="9/12/2023"></a>
#### 9/12/2023 - Building an Animal Hierarchy and Starting the Factory

  Much was learned this day, though progress was not as fast as expected. The milestones reached this day were the acquisition of simple animal models to use, the construction of an CAnimal hierarchy, some light reworking of the Animal Selector Widget 2 to fit the purposes of this week, and the start of the factory to be used.

  Below is an image of some of the animal assets collected from [here](https://www.cgtrader.com/free-3d-models/animals/other/lowpoly-animals-pack-e9e2d564-1080-42a0-af25-216b217c9de6). As might be noticed, a chicken is present. It (the chicken) has been added to the enumeration that is planned to be utilized by the factory.

  ![AnimalAssets](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/c481543c-e7a4-4551-86e7-c166828d9621)

  The animal selection menu has been slightly adjusted to account for spawning animals. The Blueprint changes will be shown later.

  ![AnimalWidgetNowSpawns](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/1f2b60d0-df5d-4128-98fe-4d073d912403)

  On the C++ side of things, many new classes were created and the CAnimalSelector was renamed to CAnimalProcessor to better reflect its purpose.
  
  ![AnimalC++Files9-12](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/95f8cfc2-c64e-412b-a05f-6a76326f47c4)

  The CAnimalBase was derived from Unreal's Character class. In retrospect, it might have been more ideal to derive it from the Actor class so as not to be forced to use a skeletal mesh (which was a bit of an ordeal on its own and will likely be in the next days to come), but it is providing a good learning oppertunity and allows built-in movement functionality, should that ever be desired. For now, none of the derived animals have been altered beyond their creation. Below are the files for CAnimalBase. Though there were some changes made along the way when trying to figure out mesh setting, they were ultimately reverted and are at the default settings. It was also at this point, when researching mesh setting through C++, that I saw a suggestion that external assets such as meshes should probably be set in Blueprints since their file paths would have to be hard-coded in C++, something that does not sound at all desirable. For the time being, the mesh is set at the blueprint layer (more on that later).
  
  ![CAnimalBaseH1](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/a393a040-1efe-41e9-a21f-6f2915d9665d)
  
  ![CAnimalBaseCPP1](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/dfdca25b-d121-4647-95dd-77a51b1673e0)

  The factory is proving tricky to learn in the Unreal Engine setting, but progress is slowly being made. The facotry was derived simply from the Unreal Object class. Following and stitching together a few tutorials and other pieces of infomation found online to adjust for the specific circumstances, the following result was reached. A function to spawn an animal takes in a CAnimalT to determine which animal to create and a transform value is passed in to define where in the world the animal is to spawn. That said, it became apparent that Unreal Engine does not particularly like the normal C++ method of instanciating objects when it comes to UObjects and will refuse to compile. The alternative is, instead of using the clasic `new` operator, to physically spawn the actor in the world. This took a while to get working properly, and while CAnimal subclasses can't be chosen to be spawned yet, the basic CAnimalBase is able to be spawned in the world and returned for the Blueprint's reference. The next large step here would be to figure out how to set AnimalToSpawn desirably at the C++ level so that the CAnimalT may be used to correctly select an animal.
  
  ![CAnimalFactoryH1](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/2312d891-1693-411e-adb5-b881b7d29133)
  
  ![CAnimalFactoryCPP1](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/840aaa5e-4015-43bf-915c-f1807da5afd1)

  Lastly, the following is the additions made to the widget Blueprint to implement the factory so far. Upon creation, the widget creates an CAnimalFactory to store for reference at the same time as the CAnimalProcessor. Using this reference, the click of a button will tell the factory to spawn an animal. Again, while a CAnimalT is being passed in, it is not being used quite yet, and a CAnimalBase will be spawned based on the location of the widget's Owner, the physical object the user interacts with to prompt the menu. Eventually, the Set Animal node will be implemented and likely will be converted to an array of Animals instead of just one as it is now. The final part of this block is the dreaded mesh-set mentioned earlier. The presence of this portion, as of now, is used to confirm that an actor is indeed being spawned, in addition to where it is. The big question now is that if the mesh isn't desirable to be set at the C++ level where the asset would be hard referenced, what is the best way to set it at the Blueprint level? Is the Blueprint level actually the answer or should it just be set at the C++ level instead? Hopefully this does not prove to be too much of a challenge. 
  
  ![AnimalSpawningWidgetBP1](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/c8ef374d-ab1a-49ae-be5d-eea362d709df)

  ![CAnimalSpawned](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/b142a0e1-62df-4b84-a5de-9d1d7fdeaca7)

  Hopefully, the end of the next full day of work will see the factory fully functioning as intended and the mesh problem will be solved.

<a name="9/15/2023"></a>
#### 9/15/2023 - Functioning Factory and Mesh Problems

  Where the factory previously only spawned a CAnimalBase, it has been improved to actually be able to spawn an animal based on the input desired CAnimalT:
  
  ![FactorySpawnAnimalDefinition](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/8c58c8ac-2310-47c4-afd6-0bf2c581f63b)

  The differences for each AnimalBase subclass end at their name and are currently functionally identical to each other. Their purpose is currently only to showcase a working simple factory.
  
  Below is the simulator results using the Select button. It has been implemented at the Blueprint level so that the animals spawn in a line and stop spawning after the 5th for the sake of simplicity. The row of animals to the left are just static meshes on display and are not related to the factory in any way.
  
  ![AnimalSpawnerBasic](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/28e090f0-e7f0-4249-bdd2-90d4ed367535)

  While it appears that this week's goal was reached, and, in a way, it was, the mesh problem was not yet solved. To demonstrate the functioning factory, the meshes were set at the Blueprint level.
  
  ![BPAnimalMeshes](https://github.com/wesles2k1/IndependentStudyWithUnrealEngine/assets/98764304/a4405f9f-1172-45f0-a655-e478b5521c28)

  After consulting the supervisor for this independent study, it seems the best course of action will next be to learn about using DataTables as a configuration of sorts to hold data used to construct objects, such as meshes. This way, asset files may be renamed or moved around without breaking anything. This also will likely be useful in setting additional data for objects to be used so that the factory may get access to this information in order to correctly instantiate the object it wishes to make. Additionally, it would seem that it is desirable to create a factory at a wider scope than where it currently is, such as at the map level or even the game level. [This](https://www.youtube.com/playlist?list=PLitYOdh3OOzhJBCRqYZEGBzJYemA-SH8Z) tutorial series seems to discuss this in great detail and will likely be used in improving this project. Even beyond this specific problem, this tutorial series seems extremely relevant in later parts of this project, expecially if the chosen path is that of an inventory system.
  
  Still, even when this solves the issue of how to set a desired mesh through the factory, there is still the question of how one may apply transformations or other visual adjustments to something like this mesh without the aid of a viewport. Trial and error through data values comes to mind, but that hardly seems effective.

  It seems that the correct course of action by this point would be to take a step back, watching through a bit of the previously mentioned tutorial series and exploring the Factory Method and Abstract Factory design patterns a bit more to get a better understanding of their purpose, importance, and methods of implementation, both internally and externally. The goal for next week will likely be improving upon what has been done this week: improving the factory's spawn method and level of implementation and implementing a data table for the factory to use in spawning animals.
