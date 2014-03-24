#ifndef RAW_BUFFER_HPP
# define RAW_BUFFER_HPP

# include <cstring>

template<unsigned int size>
class RawBuffer
{
public:
  RawBuffer()
  {
    bzero(_buffer, size);
  }
  ~RawBuffer() {}
  RawBuffer(RawBuffer const &other)
  {
    memccpy(this->_buffer, other._buffer, size);
  }
  RawBuffer	&operator=(RawBuffer const &other)
  {
    memccpy(this->_buffer, other._buffer, this->size);
  }

  char	*getBuffer()
  {
    return _buffer;
  }

  char		&operator[](unsigned int index)
  {
    return _buffer[index];
  }

private:
  char		_buffer[size];
};

#endif