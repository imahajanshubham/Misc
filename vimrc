

"| ----- Pathogen Plugin Manager.       ----- |
			
	 execute pathogen#infect()
	     set nocompatible
	filetype off



"| ----- Vundle Plugin Manager - START. ----- |

	 set rtp+=~/.vim/bundle/Vundle.vim
	call vundle#begin()



"| ----- Plugins to install.            ----- |

	"Vundle Plugin Manager Installer.
	Plugin 'VundleVim/Vundle.vim'

	"Syntax Checker.
	Plugin 'scrooloose/syntastic'

	"Snippets.
	Plugin 'honza/vim-snippets'
	Plugin 'sirver/ultisnips'

	"Auto-completion for Quotes, Brackets etc.
	Plugin 'raimondi/delimitmate'
	
	"Code auto-completion + fuzzy search.
	Plugin 'valloric/youcompleteme'
	
	"File browser.
	Plugin 'scrooloose/nerdtree'
	
	"Material theme.
	Plugin 'NLKNguyen/papercolor-theme'



"| ----- Vundle Plugin Manager - END.   ----- |

	    call vundle#end()
	filetype plugin indent on
	filetype plugin indent on



"| ----- Syntastic Settings.            ----- |

	let g:syntastic_always_populate_loc_list = 1
	let g:syntastic_auto_loc_list            = 1
	let g:syntastic_check_on_open            = 1
	let g:syntastic_check_on_wq              = 0
	
	"Better symbols.
	let g:syntastic_error_symbol             = '✗'
	let g:syntastic_warning_symbol           = '!'



"| ----- YouCompleteMe Settings.        ----- |

	"Auto-completion Sources.
	let g:EclimCompletionMethod         = 'omnifunc'
	let g:ycm_server_python_interpreter = 'python'
	let g:ycm_global_ycm_extra_conf     = '~/.vim/bundle/youcompleteme/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
	let g:ycm_global_ycm_extra_conf     = '~/.vim/bundle/youcompleteme/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
	
	"Auto-completion Settings.
	let g:ycm_min_num_of_chars_for_completion               = 1
	let g:ycm_complete_in_comments                          = 1
	let g:ycm_collect_identifiers_from_tags_files           = 1
	let g:ycm_seed_identifiers_with_syntax                  = 1
	let g:ycm_collect_identifiers_from_comments_and_strings = 1

	"Preview Window Settings.
	set completeopt-=preview
	let g:ycm_add_preview_to_completeopt                    = 1
	let g:ycm_autoclose_preview_window_after_completion     = 1
	let g:ycm_autoclose_preview_window_after_insertion      = 1
	let g:ycm_collect_identifiers_from_tags_files           = 1

	"Error Diagnostics Settings.
	let g:ycm_show_diagnostics_ui                           = 1
	let g:ycm_enable_diagnostic_highlighting                = 1



"| ----- Snippets Trigger Settings.     ----- |

	let g:UltiSnipsExpandTrigger         = "<tab>"
	let g:UltiSnipsJumpForwardTrigger    = "<c-b>"
	let g:UltiSnipsJumpBackwardTrigger   = "<c-z>"
	let g:ycm_key_list_select_completion = ['<Down>', '<Up>']



"| ----- Powerline Statusline Settings. ----- |

	set rtp+=$HOME/.local/lib/python2.7/site-packages/powerline/bindings/vim/
	set laststatus=2
	set showtabline=2
	set noshowmode
	set t_Co=256
	
	"Powerline with other Plugins.
	set statusline+=%#warningmsg#
	set statusline+=%{SyntasticStatuslineFlag()}
	set statusline+=%*



"| ----- Key Mappings.                  ----- |

	"Basic Copy and Paste etc..
	vmap     <C-c> "+yi
	vmap     <C-x> "+c
	vmap     <C-v> c<ESC>"+p
	imap     <C-v> <ESC>"+pa
	imap     <C-z> <Esc>ui
	map      <C-a> <esc>ggVG<CR>
	
	"Buffer Switch.
	nnoremap <C-e> :bnext<CR>
	nnoremap <C-q> :bprev<CR>
	
	"Nerd Tree Trigger.
	map      <C-n> :NERDTreeToggle<CR>



"| ----- Theme Settings.                ----- |

	set background=dark
	colorscheme PaperColor



"| ----- Utilies + Misc. Settings.      ----- |

	set title
	set number
	set hidden	
	set clipboard+=unnamedplus
	set cursorline
	set mouse=a
	set tabstop=4
	set shiftwidth=4
	set autoindent
	set smartindent

	"Misc.
	syntax on 
	behave mswin
