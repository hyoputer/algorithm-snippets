template <typename ... Args>
std::string string_format(const std::string &format, Args ... args)
{
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0' 
    if (size <= 0) { throw std::runtime_error("Error during formatting."); 
    } 
    std::unique_ptr<char[]> buf(new char[size]); 
    snprintf(buf.get(), size, format.c_str(), args ...); 
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside 
} 
    
// 사용법 std::string sResult = ""; std::string stringValue = "string..."; int intValue = 999; sResult = string_format("string format example : %s / %d", stringValue, intValue);

출처:
https: //jangjy.tistory.com/359 [살다보니..]