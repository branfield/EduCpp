
sub crc
{
	my $s = shift;
	my $r = 0x00;

	for( my $i=0; $i<length($s); $i++ )
	{
		my $c = substr($s,length($s)-1-$i,1); //функция substr выделяет подстроку. substr (сама строка, смещение, длина)

		my $x = ord($c) ^ $r; // ^ возвращает исключенные побитово операнды (исключающее ИЛИ)

		$r = 0x00;

		if ($x&0x01) { $r^=0x5E; }
		if ($x&0x02) { $r^=0xBC; }
		if ($x&0x04) { $r^=0x61; }
		if ($x&0x08) { $r^=0xC2; }
		if ($x&0x10) { $r^=0x9D; }
		if ($x&0x20) { $r^=0x23; }
		if ($x&0x40) { $r^=0x46; }
		if ($x&0x80) { $r^=0x8C; }
	}

	return $r;
}


	open(F,"<01 src.txt") || die;
	open(FD,">03 result.txt") || die;

	while( my $l=<F> )
	{
		$l =~ s%[\r\n ]%%g; 
	// \r - перевод символа каретки (CR)
	// \n - символ новой строки (LF, NL)
	// %%g - global (?)

		unless ($l =~ m%[0-9A-F]{16}% ) //пока не
		// =~ проверка
		// {16} - 16 символов
		// [0-9A-F] - любые цифры от 0 до 9 и любые буквы от A до F
		{
			print FD "	\n";
			next;
		}

		my $lbin = pack("H*",$l); 
		//упаковывает заданные аргументы в бинарную строку
		// HEX с верхнего разряда
		
		# 0  1 2 3 4 5 6 7
		# cr 0 0 0 . . . 01

		substr($lbin,1,3) = "\x00\x00\x00";
		my $crc = crc( substr($lbin,1,7) );

		substr($lbin,0,1) = chr($crc);

		my $ld = unpack("H*",$lbin);
		$ld = uc($ld);

		print FD "$ld\n";
	}

	close(F);
	close(FD);

