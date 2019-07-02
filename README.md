 # Drawing Shapes 
 
 In this assignment, we will implement a simple graphics system using an ASCII implementation, where a point is a character position and we will write to the graphics system by placing a "*" character in a position. 
###### Properties Of Functions And Classes :
- DisplayWindow(n,m) dynamically creates an area of size n by m on the screen. Points on the screen are addressed using (x,y) Cartesian Coordinates.
- A DisplayWindow w has a current position w.current(). Initially, current is Point(0,0). The current position can be set by w.current(p) where p is a Point. 
- A point is specified by a coordinate pair Point(x,y).  
- A Line is specified by a pair of points: Line(w.current(), p2).
- A Rectangle is specified by its top left and bottom right corner: Rectangle(w.current(), Point(10,10)).
- Class Shape is the common interface to Dots, Lines and Rectangles.
- A Point is not a Shape. A Dot, Dot(p), can be used to represent a Point p on the screen.
- A Shape is invisible unless it is draw() n. For example: w.draw(Dot(w.current())).
- Every Shape has 9 contact points: e(east), w(west), n(north), s(south), ne, nw, se,sw and c (center). For example: Line(x.c(), y.nw()); creates a line from x’s center to y’s top left corner. Note that south and north directions are defined according to the display window; hence, north of a shape is on the upper part, while south is on the lower part on the display window (Figure 1, Figure 2).  
 
 
- ![Untitledwww](https://user-images.githubusercontent.com/43285289/60514189-9ef5e300-9ce1-11e9-8c1f-30a7a940e5c6.png)
![2222](https://user-images.githubusercontent.com/43285289/60514236-bcc34800-9ce1-11e9-9ddd-365472f47995.png)

- After draw()ing a Shape, the current position is the Shape’s se(), except for the Line shapes; the current position is set to the second end point of a line. For example: w.draw(Line(Point(10,10), Point(20,20))); Shape’s current position becomes Point(20,20). 

- After drawing is complete, you can show() the content of your DisplayWindow w using w.show().

- Display buffer’s origin, i.e. Point(0,0), is depicted on the top left corner of the window. So, the Cartesian x coordinate is increasing in the right direction, while y-coordinate is increasing in the downward direction. Note that, in this display convention, bottom left corner of a rectangle is displayed as the top-left corner on the screen, although in the Cartesian coordinates it’s still bottom left corner.  
A cartesian coordinate, Point(x,y) can be modified by an amount nusing: right(n), left(n), up(n), down(n). For up() and down() functions, up() sets the point to the upper side of the screen (by reducing the y-coordinate) and down() in the opposite manner. when no argument is passed to these functions, n is 1, i.e. related coordinate is modified only by 1. For example: p.right(); increments the  x coordinate by 1. As a result, these functions return the Point with the new coordinates. 


Testing: 
There are 4 sample output text files for us to test your codes at Ubuntu. These text files look in a different format in Windows. If we want to see and use them in Windows operating system, we need to change the line endings to Windows. we can do this easily on Windows by using Notepad++ program, using Edit/EOF Conversion Menu (Click the Windows submenu there). 
- Compile our codes using :  
`>g++ DrawShp.cpp -o PA4`

You are provided with a sample Main function. The basic functionality of your DisplayWindow and Shape classes aretested with 3 functions, for all these functions expected outputs are provided as output_dots.txt, outputs_lines.txt and output_rectangles.txt. After you tested your basic Shape functions, uncomment the call drawHome() function to test all functions simultaneously;the expected output of this function is provided to you in output_home.txt file. Note that DisplayWindow() size has to be allocated dynamically, since it can change to different amounts in different scenarios. 
