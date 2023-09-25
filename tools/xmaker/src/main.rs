use std::collections::HashSet;

const HASHES: [u32; 22] = [
    0x13ADB, 0x21D0D, 0xBCA887, 0x15B6DCF, 0x289F266, 0x3D9E934, 0x4E130F4, 0x4EE32E4, 0x4F130F4,
    0x568F6CF, // 0x6776575, // xw_ex_5170.se or xw_ex_5180.se
    0x7EA6114, 0x19C54507, 0x1D140A5D, 0x1EC25DF9, 0x57C5C80D, 0x80088AFF, 0x86E3F5BF, 0xA6533CF1,
    0xAEA861ED, 0xC4F489EF, 0xC4FEB18F, 0xD83A48FD,
];

#[inline]
fn advance_hash(hash: u32, c: char) -> u32 {
    (hash << 1) ^ (((c as u32) << 16) % 69665)
}

fn find_hash(prefixes: &Vec<&str>, suffixes: &Vec<&str>, chars: &Vec<char>, hashes: &HashSet<u32>) {
    let mut i = 0;
    let mut num_digits: usize = 0;
    let log_freq: usize = 1000000;
    let num_million = log_freq / 1000000;

    loop {
        for prefix in prefixes {
            for suffix in suffixes {
                let mut hash: u32 = 0;

                for char in prefix.chars() {
                    hash = advance_hash(hash, char);
                }

                let mut j = i;
                while j > 0 {
                    let char = chars[j % chars.len()];
                    hash = advance_hash(hash, char);
                    j /= chars.len();
                }

                for char in suffix.chars() {
                    hash = advance_hash(hash, char);
                }

                if hashes.contains(&hash) {
                    let mut tstr = prefix.to_string();
                    let mut j = i;
                    while j > 0 {
                        let char = chars[j % chars.len()];
                        tstr.push(char);
                        j /= chars.len();
                    }
                    tstr.push_str(suffix);
                    println!("Found a hash collision: {:X} -> {}", hash, tstr);
                }
            }
        }

        i += 1;
        if (i % log_freq) == 0 {
            println!("{}M", i / log_freq * num_million);
        }

        if i > chars.len().pow(num_digits as u32) {
            num_digits += 1;
            println!("{} digits!", num_digits);
        }
    }
}

fn main() {
    //println!("{:X}", get_hash("title/title.tm2"));
    let caps: [char; 26] = [
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    ];

    let lowers: [char; 26] = [
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    ];

    let digits: [char; 10] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];

    let mut chars: Vec<char> = Vec::new();
    chars.extend_from_slice(&caps);
    chars.extend_from_slice(&lowers);
    chars.extend_from_slice(&digits);
    chars.push('_');
    chars.push('.');
    chars.push('-');
    //chars.push('/');
    //chars.push(' ');

    let prefixes = vec![
        "",
        "gumi/",
        "xa_",
        "xs_",
        "worldmap/",
        "worldmap/bgs/",
        "worldmap/ev/",
    ];

    let suffixes = vec![
        ".mset", ".mdls", ".vset", ".evm", ".dat", ".ard", ".bin", ".img", ".dpx", ".dpp", ".bgm",
        ".wpn", ".se", ".ev", ".wd", ".vsb", ".tzb", ".mag", ".wdt", ".mlb", ".irx", ".x", ".BIN",
        ".dbt", ".aml",
    ];

    find_hash(
        &prefixes,
        &suffixes,
        &chars,
        &HASHES.iter().cloned().collect(),
    );
}
