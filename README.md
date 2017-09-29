# GameDevOctober
GameDevOctober is the first of a series of projects for the GameDev Interest Group at PantherHackers.  
For this project, we are taking the base template given by the Top Down example from Unreal Engine, and working on adding our own interactive flavor to it.  

# Using GameDevOctober
I have never hosted an Unreal project on GitHub before, and am sure the repo will begin in a buggy mess, don't let that dishearten you! You can always ask for help on Slack.  
Reading online, first make a C++ project within Unreal, calling it GameDevOctober. Be sure to close out after creation.  
Navagating to the folder above the project's folder, enter `git clone` followed by the GitHub clone url. This _should_ copy the contents of the GitHub project into your Unreal project. You may need to authorize overwriting files.  
From there, it should behave like any other git project.  

# Current Functionality
Currently by default, the main character can press Q, W, E, and R to trigger an event in game. This is the "base" functionality of every HeroComponent.  
You can press `,` to trigger a swap of Hero Components to a testing template called `Luux`. Most of the functionality is the same, but with time Luux is meant to serve as an example of what you can do.  

# Your own implementation
To make your own Hero, in the editor find the `C++ Classes` folder, and right click `HeroComponent` and select the top option "Create C++ Class derived...", Name it what you want, like "TotallyNotVeigarrrrrrHeroComponent", and select Create Class (Be sure to name it right, Unreal doesnt play nice with renaming).  
You will be given an empty .cpp file and nearly empty .h file with that name. Open the HeroComponent.h and .cpp files, and the same for LuuxHereComponent. You can use these as a reference for what needs to be done (LuuxHeroComponent is derived from HeroComponent, just like your new class).  
Inside `GameDevOctoberPlayerController.h`, the class for the HeroComponent of the character to switch to is set under the `ChangeHeroComponent()` method. Change `ULuuxHeroComponent` to your own implementation and all should play nice. NOTE: Be sure your project can compile BEFORE you do this, otherwise you will have trouble.  