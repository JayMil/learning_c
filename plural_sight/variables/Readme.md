# Variables

In c local int variables that are not set to a value will use the int value currently stored in that memory location
Non static global int variables are initialized to 0 if a value is not provided.
Non static global variables may collide with other non static global variables of the same name.
When they collide you will not get an error, rather they will just both point to the same memory location.
Static global variables will get their own memory locations and will be initialized to 0 if not defined.
