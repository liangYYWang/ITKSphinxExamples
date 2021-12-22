#ifndef MultiThreadedImageFilter_h
#define MultiThreadedImageFilter_h

#include "itkImageToImageFilter.h"

namespace itk
{
template <class TImage>
class MultiThreadedImageFilter : public ImageToImageFilter<TImage, TImage>
{
public:
  ITK_DISALLOW_COPY_AND_MOVE(MultiThreadedImageFilter);

  /** Standard class type alias. */
  using Self = MultiThreadedImageFilter;
  using Superclass = ImageToImageFilter<TImage, TImage>;
  using Pointer = SmartPointer<Self>;

  using OutputImageRegionType = typename Superclass::OutputImageRegionType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(ImageFilter, ImageToImageFilter);

protected:
  MultiThreadedImageFilter() = default;
  ~MultiThreadedImageFilter() override = default;

  void
  DynamicThreadedGenerateData(const OutputImageRegionType &) override;
};
} // namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#  include "MultiThreadedImageFilter.hxx"
#endif


#endif // MultiThreadedImageFilter_h
