# Git 笔记

## 踩过的坑

1. git 命令中不能随便加 -f，通常代表 force。有过 git checkout -f 导致已经add的文件都丢失的情况

## 其他命令

| 命令                    | 作用                        |
| --------------------- | ------------------------- |
| git fsck --lost-found | 在 .git/lost-found 找到丢失的文件 |
| git reflog            | 可以查看HEAD的变化               |
|                       |                           |

