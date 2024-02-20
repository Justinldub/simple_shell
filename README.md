<h1>Simple Shell Project v-1.0.0</h1>
<br>
<p>A simple unix shell built using C programming language
Its use is to leverage the unix operating system's kernel
in order to allo users to take control of the unix system's input and output
functionalities from the commandline by making use of the builtin fuctionalities for I/O
</p>
<br>
<h4>Core system functions and utils</h4>
<ul>
	<li>1) loop.c - A program that creates a loop, displays the prompt into the terminal while awaits user input</li>
	<li>2) readline.c - A program that read a command from the terminal from the system's standard input STD_INPUT</li>
	<li>3) splitline.c - A program that takes the inputed command from the terminal and split it to meaning full tokens, then analyze them and prepares them for execution.</li>
	<li>4) execute.c - A program that taks the command converted to tokenized string in an array of arguments, creates a new chile process and execute the commands.</li>
	<li>5) main.c - The entrypoint of the program.</li>
	<li>6) shell.h - A header  file for defining core components for the shell</li>
</ul>
<br>
<h4>Shell Commands</h4>
<p>Built in commands</p>
<ul>
	<li>1)_cd.c - A program that navigate the directory system</li>
	<li>2)_exits.c - A program that terminate the shell program</li>
	<li>3)_help.c - A program that prints the help menu into the terminal for reference purpose and general knowledge of the shell infrusture.</li>
	<li>4)util.h - A header file that defines the components for the shell commands</li>
</ul>