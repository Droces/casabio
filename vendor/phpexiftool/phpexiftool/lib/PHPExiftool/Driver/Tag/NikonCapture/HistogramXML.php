<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\NikonCapture;

use PHPExiftool\Driver\AbstractTag;

class HistogramXML extends AbstractTag
{

    protected $Id = 138025509;

    protected $Name = 'HistogramXML';

    protected $FullName = 'NikonCapture::Main';

    protected $GroupName = 'NikonCapture';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'NikonCapture';

    protected $g2 = 'Image';

    protected $Type = 'undef';

    protected $Writable = true;

    protected $Description = 'Histogram XML';

    protected $flag_Binary = true;

    protected $flag_Permanent = true;

}
