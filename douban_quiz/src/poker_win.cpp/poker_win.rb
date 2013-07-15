
count = 0;
file = File.new("data")
reg = /(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)\s(\w+)/
a = []
b = []

class Node
	attr_accessor :value, :color
	def initialize(value, color)
		@value = value
		@color = color
	end
end
def degree(poker)
	isSameColor = true;
	firstColor = poker[0]
	poker[1,4].each { |i| isSameColor = false if i.color != firstColor } 
	if( poker[0] == 10 && poker[1] == 11 && poker[2] == 12 && poker[0] == 13 && poker[4] == 14 && isSmaeColor)
		return 10;
	elsif( 
end


file.each_line { |line|
	line =~ reg
	a.clear; b.clear
	a << $1 << $2 << $3 << $4 << $5;
	b << $6 << $7 << $8 << $9 << $10;
	alter = proc do |item|
		x = item[0]
		y = item[1]
		case x
			when "A" then x = 14
			when "K" then x = 13
			when "Q" then x = 12
			when "J" then x = 11
			else  x = x.to_i
		end
		item = Node.new(x, y)
	end
	a.collect! &alter
	b.collect! &alter
	
	criterion = proc { |x, y|
		x.value <=> y.value
	}
	a.sort(&criterion)
	b.sort(&criterion)
	
	puts a
	puts b
}
