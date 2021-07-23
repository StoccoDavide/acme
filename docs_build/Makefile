github:
	@rm -rf xml
	@rm -rf sphinx/_build
	@rm -rf sphinx/api
	@cd sphinx; make clean; make html; ruby filter.rb; cd ..
	@make install

install:
	@cd sphinx; rm -rf ../../docs/*; cp -a _build/html/. ../../docs; cd ..

py:
	pip install sphinx
	pip install wheel
	pip install sphinxcontrib-fulltoc
	pip install sphinxcontrib-email
	pip install cloud_sptheme
	pip install exhale
