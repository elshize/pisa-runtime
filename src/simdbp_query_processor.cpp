#include <index_types.hpp>
#include <memory_source.hpp>

#include "simdbp_query_processor.hpp"

SimdBpQueryProcessor::SimdBpQueryProcessor(std::string const& path, std::string const& wand_data_filename)
    : m_index(pisa::MemorySource::mapped_file(path)),
      m_wdata(pisa::MemorySource::mapped_file(wand_data_filename))
{}

auto SimdBpQueryProcessor::process_query(pisa::Query) -> std::vector<std::pair<float, uint64_t>>
{
    return {};
}

auto SimdBpQueryProcessor::processor(
    std::string_view algorithm, ScorerParams scorer_params, std::size_t k) -> ProcFunc
{
    return resolve_query_processor(m_index, m_wdata, algorithm, scorer_params, k);
}

SimdBpQueryProcessor::~SimdBpQueryProcessor() {}
