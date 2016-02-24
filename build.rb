#!/usr/bin/env ruby

if ARGV.size != 1 || %w(--help -h).include?(ARGV[0])
  puts "Usage: #{__FILE__} YAML_FILE"
  exit 1
end

require "yaml"
require "erb"

def string(value)
  value.nil? ? "NULL" : "\"#{value}\""
end

def generate(name)
  tpl = File.read("#{name}.erb")
  erb = ERB.new(tpl)
  File.write("gen_#{name}.h", erb.result)
end

doc = YAML.load_file(ARGV[0])

game = doc.fetch('game')
rooms = game.fetch('rooms')

generate :rooms
generate :game
