<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPXmpDM;

use PHPExiftool\Driver\AbstractTag;

class TracksMarkersCuePointParamsValue extends AbstractTag
{

    protected $Id = 'TracksMarkersCuePointParamsValue';

    protected $Name = 'TracksMarkersCuePointParamsValue';

    protected $FullName = 'XMP::xmpDM';

    protected $GroupName = 'XMP-xmpDM';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-xmpDM';

    protected $g2 = 'Image';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Tracks Markers Cue Point Params Value';

    protected $flag_List = true;

}
