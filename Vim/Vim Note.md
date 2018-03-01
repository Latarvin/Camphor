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
w W / B b : 前/后词
^ / 0 : 最前
$ : 最后
z回车 : 下滚，光标在文中位置不变但置于上方
zz : 类似上一个，置于中间
```

```
7gg / 7G / :7回车 : 第7行
gg : 最初
G : 最末
:$ : 最末
```

```
ctrl g : 文件行数显示
g ctrl g : 细节，词数等
:set ruler
:set noruler
:set ruler! : 切换
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

video 21 insert

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

