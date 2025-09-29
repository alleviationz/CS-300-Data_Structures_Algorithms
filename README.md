# CS300

#What was the problem you were solving in the projects for this course?

The problem being solved was to implement an appropriate data storage structure that we recommended, and save course information into it by parsing a file of course information.

#How did you approach the problem? Consider why data structures are important to understand.

The approach to the problem began with pseudocode to create a sound design. I wrote pseudocode for three different storage structures, and analyzed their runtime complexities.
Then I chose initially chose to use a hash table considering the potential size of the structure with additions, but ended up creating a binary search tree. Data structures are important
to understand because different data structures can be more effective for different projects. Understanding all of them increases one's toolbelt and allows us to create faster, more
efficient algorithms and potentially save space.

#How did you overcome any roadblocks you encountered while going through the activities or project?
I encountered a big issue when implementing my hash table from my pseudocode. It kept throwing errors that I did not understand and couldn't find much help to resolve the issues.
I started trying to implement a binary search tree instead and came to similar errors when trying to pass in a data structure reference as a function parameter. I eventually overcame this issue
by passing in a vector reference, saving courses to the vector, iterating through the vector, and then passing the each course into the data structure instead of trying to directly call the data structure functions from
within the file parsing function.

#How has your work on this project expanded your approach to designing software and developing programs?

Firstly it has reinforced my knowledge of c++. I had little capability with c++, but I feel more comfortable now. Secondly, it has proved to me that the design and structure of the code
that is used is much more important that just jumping in and coding a less efficient solution to complete a project more quickly. Lastly, encountering a lot of errors through translating
my pseudocode into actual code has shown me that even if a design seems very thought out, you can't know what you don't know and jumping in helps to expand your perspective of issues
that you may encounter.

#How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

This course and these projects have evolved the way I think about programs in giving more focus to the design, but also pushing me attempt to implement
dummy prototypes of my design before wasting too much time on something that may not work. While I was also previously aware of not hard-coding solutions
and making flexible coding, this course has also really reinforced that point.
