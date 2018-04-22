# Vim Note

### video 005 quickstart

```
d3w : delete 3 words
di" : delete inside quotation"

action + egictive + object
```

### video 008 navigation 

```
ctrl+f : page down
ctrl+b : page up
```

```
w W / B b : forward / backward word
^ / 0 : beginnign
$ : end
z <enter> : scroll down, cursor still
zz : scroll down till cursor in the middle of screen
```

```
7gg / 7G / :7 <enter> : line No.7
gg : beginning of the file
G : end of the file
:$ : end of the file
```

```
ctrl g : show line num
g ctrl g : detail, word num, etc
:set ruler
:set noruler
:set ruler! : switch ruler
```

### video 011 deleting

```
x : delete 1 character right (cursor)
X : delete 1 char left 
dw : delete word right, till next word
dl, dj: delete 1 char
dj : delete current line and next
dk : delete current line and above
d0, d$
d$ = D
dd : delete line
3dd
5dw
d3w : delete 3 words
2d3w
[count]operation[count]{motion}
. : repeat
dW : delete with ,
```

### video 014 & 016 help

```
:help :h
:help <command>
:q
：help count

ctrl o : jump backward section
ctrl i : jump forward section
ctrl ] : jump to certain def

ctrl w ctrl w : keep help open while editing, enter again to jump back

:h + :q + ctrl d : auto make up
:h + :q + ctrl d + tab
:h + sth + tab
shift tab
:set wildmenu : menu while enter tab

:help ctrl-f = :help ^f
ctrl-g = :f : show file name
```

### video 017 cut copy and paste

```
p : after cursor
dd + p : paste line below
dd + P : paste line above
x + p : swap char 

y : yank
yw + p
yy : yank line

u : undo
ctrl r : redo
```

```
:reg : show register
"0 + p : paste yank reg
"_ : blackhole reg
"2 + p

# named reg
"a + yy : save to 'a' reg
"A + yy : append to 'a' reg

:reg z
"h2p = "2hp
```

### video 021 inserting

```
I : 行首插入
a : insert after cursor
A : insert at the end of line
o / O

80i + '*'
5o + '#'
```

```
R : replace when typying
r : replace 1 char
c: change
cw : change word
c$ = C
cc : change whole line
```

```
~ : change to upper/lower case (switch)
g~w : change word to upper/lower case (switch)
g~~ : whole line
gUw : change word to upper case
gUU
guw
guu
```

```
J : join 2 line and add a space (no .) / 2 space (with .)
gJ : not add sapce 
3J

```

### video 022&023 search find and replace

```
f + 'b' / 'A' : find b / A in the line
fa + ; : repeat search a (forward)
fa + , : repeat search a (backward)
Fa : search backward

ti : move before 'i'
Ti : move after 'i'

dtw = df<space> = dW

/and : search
/and, then n/N : find next / previous

setting is/incsearch : highlight
:set is? <enter> : show what the state of 'is'

:set hls/hlsearch

/and + cw + '&' + esc + n + .

* / # : next / previous same word

d + /This + <enter> : delete until This
"a + y + /z
```

```
:s/old/new <enter> : replace all 'old' with 'new'
:s/old/new/<enter> : replace only current line and first occurance
:[range]s/old/new/[flag] : syntax
:s/old/new/g <enter> : replace only current line
:1s/old/new/ <enter> : replace sth on line 1
:1,5s/for/FOR/g
$ : last line
. : current line
.,$ : current line to last line
% : entire file

/Pattern 1/,/Pattern 2/
:/Global/,/Local/s/net/org/g : part of the pattern is enough
:/Local/,$ ...
\/sth to find '/sth'
:s/\/var\/spool/\/usr\/local = :s#/var/spool#/usr/local#

:set nu
:set nonu
:set nu!
```

### video 028

```
daw : delete a word (with space)
diw : delete in a word (without space)
ciw

das / dis : delete a sentence (with / without space)
dap / dip : delete a paragraph (with without blank line)

ci[ = ci]
() <> ""

cit : delete in a tag
diB : delete in a Block
```

### video 031

```
qa + <opreation> + q : record operation to @a
@a : repeat @a operation
@@ : repeat

qb + sth + :reg b : check recorded operations

qc + 0d2Wj + q
:s/"/'/g
:s/(//

:27,35normal @d
.,$ : current line to the file

qd + 0jDkPa<space><esc>fhDj2dd + q 

"ap + <add operation> + 0"ay$ + @a

edit vimrc /viminfo:
let @d = '<many operations>'
let @t = '$a  // TODO: ^['  (crtl + v ^)

d2W ? 
z <enter> : move down

```

### video 

```vim
v + /C : visual select to C
v + 2w + o : move to the beginning of the visual mode
```



### video 045

```
:sp : split to 2 windows, but same file
:q : quit sp mode
ctrl w + s = :sp
```

