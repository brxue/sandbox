# Cursor Moving

| Command       | Description
|---------------|----------------------------------------------------------------
|h, j, k, l     | move to left/down/up/right
|Nj             | move downwards to the N-th line
|w              | jump to next word
|W              | jump to next word (skip punctuation)
|Nw             | jump to the N-th word forwards
|b              | jump to previous word
|B              | jump to previous word (skip punctuation)
|e              | jump to end of the current word
|0              | jump to start of line
|^              | jump to the first character of a line
|$              | jump to the end of line
|fx             | move forward to the next occurence of character x (find x)
|Fx             | move backward to the next occurence of character x (find x)
|gg             | go to the 1st line
|G              | go to the last line
|:N             | go the N-th line
|[N]G           | go to the N-th line
|gd             | go to define of the function or variable under the cursor
|CTRL-u         | page up
|CTRL-d         | page down
|CTRL-f         | page up
|CTRL-b         | page down
|%              | jump to matching brace
|H              | move the cursor to the highest line of the current screen
|M              | move the cursor to the middle line of the current screen
|L              | move the cursor to the lowest line of the current screen
|ma             | make a bookmark named 'a' at current cursor postion
|`a             | go to bookmark 'a'
|:read !ls -l   | read command output to current file

# Insert

| Command       | Description
|---------------|----------------------------------------------------------------
|i              | enter to insert mode at the cursor
|I              | insert at the begining of the current line
|a              | append after the cursor
|A              | append at the end of the current line
|o              | open blank line below the current line
|O              | open blank line above the current line
|ESC            | exit insert mode

# Editing

| Command       | Description
|---------------|----------------------------------------------------------------
|u              | undo
|CTRL-r         | redo
|.              | repeat last command
|~              | switch case
|gU             | switch current character to upper case
|gu             | switch current character to lower case
|~iw            | switch case of current word
|gUiw           | switch current word to upper case (inner word)
|guiw           | switch current word to lower case (inner word)
|>>             | indent line one column right
|<<             | indent line one column left
|==             | auto indent current line

# Delete

| Command       | Description
|---------------|----------------------------------------------------------------
|x              | delete the current character
|dw             | delete the current word
|dix            | delete inner x
|dtx            | delete until next x
|dd             | delete current line
|d$             | delete to end of the line
|D              | delete to end of the line

# Copy

| Command       | Description
|---------------|----------------------------------------------------------------
|y              | yank the current character
|yw             | yank the current word
|yy             | yank the current line
|Nyy            | yank N lines afterwards
|y$             | yank to end of the line
|yix            | yank inner x
|ytx            | yank until next x

# Paste

| Command       | Description
|---------------|----------------------------------------------------------------
|p              | paste after the current cursor
|P              | paste before the current cursor

# Replace

| Command       | Description
|---------------|----------------------------------------------------------------
|r              | replace current character at cursor
|:s/old/new/g   | replace all the old with new in the current file
|:s/old/new/gc  | replace all the old with new in the current file, confirm each one

# Search

| Command       | Description
|---------------|----------------------------------------------------------------
|*              | search the current word downwards
|#              | search the current word upwards
|/pattern       | serach the pattern downwards
|?pattern       | serach the pattern upwards
|n              | repeat search in the same direction
|N              | repeat search in the reverse direction

# Exiting

| Command       | Description
|---------------|----------------------------------------------------------------
|:w             | save
|:wq            | save and exit
|:x             | save and exit
|:q             | quit but will fail if unsaved
|:q!            | quit without save

# Tab

| Command       | Description
|---------------|----------------------------------------------------------------
|:tabe          | open a new tab
|:tabe filename | open 'filename' in a new tab
|gt             | go to the next tab
|gT             | go to the previous tab

# Window

| Command       | Description
|---------------|----------------------------------------------------------------
|:split         | split current window horizontally
|:vsplit        | split current window vertically
|CTRL-w w       | switch windows

# Buffer

| Command       | Description
|---------------|----------------------------------------------------------------
|:e file        | edit 'file' in a new buffer
|:bn            | go to next buffer
|:bd            | delete a buffer (close file)

# Visual

| Command       | Description
|---------------|----------------------------------------------------------------
|v              | start visual mode
|vix            | start visual mode inner x
|V              | start linewise visual mode
|CTRL+v         | start blockwise visual mode
|I              | start insert mode in visual mode

# Useful Plugins

DrawIt

# Useful Links

http://beiyuu.com/git-vim-tutorial/
http://overapi.com/vim/
