#!/usr/bin/ruby -w

require 'fileutils'

FileUtils.rm_rf "./src/*"

FileUtils.cp_r '../src/.',                  "./src";
#FileUtils.cp_r '../src(include/.',              "./src";
FileUtils.cp_r '../submodules/Utils/src/.', "./src";

FileUtils.cp "../LICENSE.txt", "license.txt";
