set ai si noet ts=4 sw=4 sta sm nu rnu
inoremap <NL> <ESC>o
nnoremap <NL> o
"carry lines insert
inoremap <C-up> <C-o>:m-2<CR>
inoremap <C-down> <C-o>:m+1<CR>
"carry lines
nnoremap <C-up> :m-2<CR> 
nnoremap <C-down> :m+1<CR>
"carry lines visual
vnoremap <C-up> :m-2<CR>gv
vnoremap <C-down> :m'>+1<CR>gv
set t_Co=8
syntax on
au BufNewFile *.cpp 0r /home/rluan/Documentos/programming-competitive/temp.cpp
