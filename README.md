# Smart Testing System

This testing system was influenced by the concept of intelligently dividing the questions into different types of difficulty level such as easy,medium and hard so that the solver can practice on this test according to the level he falls in. After the test is finished, the solver is shown a comprehensive report about how he solved the test. 

### About the Code:

The program is written in C++ language. The code is written in Object-Oriented approach and consists of multiple custom made data structures such as linked list, stack, queue, trees, hashing and many others.

### How the test is dividing questions:

The best thing about this testing system is no one decides which question should fall in which category, instead the questions will be divided automatically based on the way they are solved overtime. The more the testing system is solved, the better it can divide the questions into categories. If any question is solved correctly by the solver, the question won't have any effect but if it is solved incorrectly, its precedence will be increased. The more the precedence of the question, the more difficult the question is. So every time the test is solved, the testing system will automatically categorize which questions falls into which category.

### About the Questions:

The code needs a text file with a particular pattern so that it can be read easily by the program(the sample file is attached in the repository). The file can consists any number of questions, each question should consists of 4 options of which 1 option will be correct, which should also be included in the file.

