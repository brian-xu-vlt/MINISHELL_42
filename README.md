# MINISHELL_42

## Team

#### [lfallet](https://github.com/lilafallet)

#### [bvalette](https://github.com/42f)

## Project

We have recreated a shell from scratch, with a minishell tester included, using only our own library (libft) and a limited range of external functions.

Minishell is compatible with macos and linux.
Tester is compatible with linux only, tested on 42's virtual machine.

## Building

``$> git clone https://github.com/42f/MINISHELL_42.git ``

``$> cd MINISHELL_42``
  
To use Minishell:
``$> make && ./minishell``

To run tester:
``$> make tester``


Includes a home made minishell tester:

![](images/screenshot.gif)

## Features

|Features   |
|:---------|
|Display prompt|
|Fetch and execute binaries|
|Logic `&&` `\|\|`|
|Single and double quotes management|
|Files redirections `>>` `>` `<` (except file descriptor agregations)|
|Pipes|
|Environment variables|
|Internal variables|
|Expansion|
|`Ctrl + D`|
|`Ctrl + \`|
|`Ctrl + C`|
|Signal catching|

|Builtins   |
|:---------|
|echo: with -n option|
|cd with relative and absolute path: with `-` options|
|pwd: no option|
|export: no option|
|env: no option|
|unset: no option|
|set: no option|
|exit: with arguments|
|history: no option|

## Line Edition

|Shortcuts   |Description              |
|:---------:|:------------------------|
`↑/↓`		|Navigate on the command history
`shift + →`	|Select while moving right
`shift + ←`	|Select while moving left
`shift + ↑`	|Copy selection
`ctrl + ↑`	|Cut selection
`shift + ↓`	|Past clipboard
`home`		|Move cursor at the commande line's starting point
`end`		|Move cursor at the command line's end
`ctrl + →`	|Move one word right
`ctrl + ←`	|Move one word left
`shift + home/end`	|Select up to the beginning/end of the command line
`shift + ctrl +  →/←`	|Select one word at a time
