#!/usr/bin/ruby -w

require 'fileutils'

#FileUtils.rm_rf "src"

lst = Dir["../src/*.c*"]
lst.each do |filename|
  FileUtils.cp filename, "./src/" + File.basename(filename);
end

lst = Dir["../include/*.h*"]
lst.each do |filename|
  FileUtils.cp filename, "./src/" + File.basename(filename);
end

FileUtils.cp "../LICENSE.txt", "license.txt"
