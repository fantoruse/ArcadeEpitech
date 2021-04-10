### Hi, we are the best arcade team: GROUP 1  
                                       -clement1.ruat@epitech.eu
                                       -antoine.desruet@epitech.eu
                                       -theo.campos@epitech.eu

### Hi, we are the worst arcade team: GROUP 2
                                        -arthur.fouquet@epitech.eu
                                        -charlie.chou@epitech.eu
                                        -olivier.marzocchi@epitech.eu

### Explication

IGame interface:

    That's an interface for games. All games will heridate from this interface, they will need to override the next methodes : 

 - Play who will be the game loop, in the core we call it in a loop for make the game run. he take as paramter an arcade::events_e who is an enum of events like the input from the player. This methode return an vector of shared pointer on IObject (that's another interface who will be in charge of all object), in this vector we got all the object we need to diplay for draw our game.
 - getName is a getter for the private variable name of the sousclass. This methode return the name of the game currently running and take no arguments.
 - isLost is a methode that's return true if the player lost the game and false if the game is currently running. He take nothing in arguments.

IObject interface:
    
    The Interface IObject is an interface dedicated to the object. 
This interface allows you to create games, it is in collaboration with the IGame interface. 
It allows you to correctly get the position of each object, and to see if they can be drawable and what type is it. 

For this there are three methods: 

  -const std::pair<int,int> getPosition();  
This method allows to retrieve the position of the object, an x and y position. 

  -const std::vector<std::shared_ptr<IDrawable>> getDrawables() 
This method return a drawable vector which object's information will be displayed on the screen. 

  -const std::string getName() 
This method allows to get the name object.

IDisplayModule interface:

This interface make possible the implementation of new graphical library.
To do so, you need to follow theses instructions.

Create a class who inherits from IDisplayModule, and then implement the following methods:

       -std::string getName() const;
Returns the name of the graphical library.

       -void init();
Create a window and open it.

       -void destroy();
Close a window and destroy it.

      -void clearWin();
Clear all window's elements.

      -void refreshWin();
Refresh the window and display the elements who were drew

        -void draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string name);
Takes a drawables's vector(Sprite, Shape, Text), the drawables's position and the drawables's name.
Then it draw it in the render window. If there is no sprite it draw a shape and if there is no sprite and no shape it display a text.
Sprite->Shape->Text

        -void Load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name)
Takes a drawables's vector and load the appropriate texture from a .png or .jpg file. who's located in resources/ folder.

      -events_e pollEvent();
Returns a event in association with the enum who's in the interface. You need to map it with the events of your graphical library.

IDrawable interface:

This interface contains information about the object that we want to display with our graphical library.
To to so, you need to follow theses instructions.

Create a class who inherits from IDrawable, and then implement the following methods:

       -const std::string &getString() const;
Returns the name of the drawable.

        -type_e getType() const;
Returns the drawable's type. You must use the enum located in the IDrawable interface.
SPRITE: for a sprite,
SHAPE: for a shape,
TEXT: for a text
and NO_TYPE: if you don't want to draw the drawable.

        -std::size_t getSize() const;
Returns the drawable's size, assuming that the drawable is square shaped.

        -colors_e getColor() const;
Returns the drawable's color. You must use the enum located in the IDrawable interface. The enum is pretty obvious so you don't need us to understand it.
