if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <Nul> 
nnoremap  h
nnoremap <NL> j
nnoremap  k
nnoremap  l
nnoremap   za
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vmap jk 
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
imap  :w
imap jk 
let &cpo=s:cpo_save
unlet s:cpo_save
set autowrite
set background=dark
set backspace=indent,eol,start
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set foldlevelstart=10
set helplang=C.
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set lazyredraw
set mouse=a
set ruler
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/vim-airline,~/.vim/bundle/vim-airline-themes,~/.vim/bundle/onedark.vim,~/.vim/bundle/ctrlp.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim/bundle/Vundle.vim,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/vim-airline/after,~/.vim/bundle/vim-airline-themes/after,~/.vim/bundle/onedark.vim/after
set scrolloff=3
set shiftwidth=4
set showmatch
set smartcase
set softtabstop=4
set splitright
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set textwidth=79
set timeoutlen=500
set ttimeoutlen=500
set updatetime=250
set wildignore=*/venv/*,*egg-info/*,*.swp,*.zip,*.exe
set wildmenu
" vim: set ft=vim :
