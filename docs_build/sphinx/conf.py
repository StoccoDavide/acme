# -*- coding: utf-8 -*-
import os
from pathlib import Path

# -- Project information -----------------------------------------------------
exec(open("../project_common.py").read())


# Setup the breathe extension
breathe_projects = { project : "../xml-cpp" }
breathe_default_project = project+"_cpp"

extensions.append('exhale');
extensions.append('breathe');

dir_path = os.path.dirname(os.path.realpath(__file__))+"../../.."
dir_path = Path(dir_path).resolve()

breathe_default_project = project

# Setup the exhale extension
exhale_args = {
  # These arguments are required
  "containmentFolder":     "./api",
  "rootFileName":          "library_root.rst",
  "rootFileTitle":         "C++ API",
  "doxygenStripFromPath":  "..",
  # Suggested optional arguments
  "createTreeView":        True,
  # TIP: if using the sphinx-bootstrap-theme, you need
  # "treeViewIsBootstrap": True,
  "exhaleExecutesDoxygen": True,
  #"exhaleDoxygenStdin":    "INPUT = ../../src"
  "exhaleDoxygenStdin":
'''
        QUIET               = YES
        INPUT               = ../../src ../../include
        EXAMPLE_RECURSIVE   = NO
        MARKDOWN_SUPPORT    = YES
        IMAGE_PATH          = ../images
        FILE_PATTERNS       = *.c *.cc *.h *.hh *.hxx

        EXTRACT_ALL            = YES
        EXTRACT_STATIC         = YES
        SHORT_NAMES            = YES
        INHERIT_DOCS           = YES
        ENABLE_PREPROCESSING   = YES
        MACRO_EXPANSION        = NO
        XML_OUTPUT             = xml-cpp
        XML_PROGRAMLISTING     = YES
        XML_NS_MEMB_FILE_SCOPE = NO
        SOURCE_BROWSER         = NO
        OPTIMIZE_OUTPUT_FOR_C  = NO
        HIDE_SCOPE_NAMES       = NO
        SEARCH_INCLUDES        = NO
        CALLER_GRAPH           = YES
        GRAPHICAL_HIERARCHY    = YES
        HAVE_DOT               = YES
        SHOW_INCLUDE_FILES     = YES
        GENERATE_TREEVIEW      = YES
        PREDEFINED           += protected=private
'''
}

# Tell sphinx what the primary language being documented is.
primary_domain = 'cpp'

# Tell sphinx what the pygments highlight language should be.
highlight_language = 'cpp'

html_theme = 'alabaster'
html_logo  = '../logo.png'

email_automode = True
autodoc_member_order = 'bysource'
