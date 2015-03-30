require 'twitter'
require "serialport"
load 'twitter_config.rb'

port_str = "/dev/cu.usbmodem1411" #this may be different for your port
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

puts "Running OpenDoor2Tweet Program"

while true do
   while (input = sp.gets.chomp) do
	puts input
		if input == "ON"
			puts "You have just pressed ON"
			system 'imagesnap -w 0.8 ./image.png'
		system 'twurl -X POST "/1.1/statuses/update_with_media.json" --file "image.png" --file-field "media[]" -d "status=Door Opened #physicalcomputing" -b -t'
		end
  end
end
 
sp.close              