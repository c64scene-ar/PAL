#!/usr/bin/env ruby

if ARGV.size != 1 || %w(--help -h).include?(ARGV[0])
  puts "Usage: #{__FILE__} YAML_FILE"
  exit 1
end

require "yaml"
require "erb"

CURRENT_DIR = File.expand_path(File.dirname(__FILE__))
EXITS = %w(north north_east east south_east south south_west west north_west)

def string(value)
  value.nil? ? "NULL" : "\"#{value}\""
end

def parse_exit_id(exit_id)
  exit_id.to_s.split('_').map { |s| s[0] }.join('').upcase
end

def exits_from_attrs(attrs)
  attrs.select { |k, _| EXITS.include?(k) }
    .map { |k, v| [parse_exit_id(k), v] }
    .to_h
end

def generate(name)
  path = File.join(CURRENT_DIR, "#{name}.erb")
  tpl = File.read(path)
  erb = ERB.new(tpl)
  File.write("gen_#{name}.h", erb.result)
end


doc = YAML.load_file(ARGV[0])

game = doc.fetch('game')
rooms = game.fetch('rooms')

generate :rooms
generate :game
